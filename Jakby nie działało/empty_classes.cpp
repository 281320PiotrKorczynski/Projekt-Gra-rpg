#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class Entity
{
public:
    Entity(int hp, int atk, int lck, int agl) : HP(hp), ATK(atk), LCK(lck), AGL(agl), level(1), exp(0) {}

    int getHP() const { return HP; }
    int getATK() const { return ATK; }
    int getLCK() const { return LCK; }
    int getAGL() const { return AGL; }
    int getLevel() const { return level; }
    int getEXP() const { return exp; }
    int levelCount=0;
    int getMaxHP() const
    {
        // Calculate and return maximum HP based on level, attributes, etc.
        return 100 + level * 10; // Example formula, adjust as per your game's design
    }

    void dealDMG(Entity* target)
    {
        int damage = ATK;
        // Apply luck factor
        if (rand() % 100 < LCK)
        {
            damage *= 2; // Double damage if lucky
            cout << "Critical Hit!" << endl;
        }
        target->takeDMG(damage);
    }

    void takeDMG(int damage)
    {
        HP -= damage;
        if (HP <= 0)
        {
            cout << "Entity died!" << endl;
        }
    }

    void gainEXP(int amount)
    {
        exp += amount;
        cout << "Gained " << amount << " experience points!" << endl;
        checkLevelUp();
    }

    void levelUP()
    {
        level++;
        increaseStats(); // Increase stats upon leveling up
        cout << "Leveling up! Current level: " << level << endl;
        levelCount=levelCount+1;
    }

    int HP;
    int ATK;
    int LCK;
    int AGL;
    int level;
    int exp;

    virtual void increaseStats()
    {
        if(levelCount==0)
        {
            HP += 10;
            ATK+=5;
        }
        if(levelCount==1)
        {
            HP += 10;
            LCK += 2;
        }
        if(levelCount==2)
        {
            AGL += 3;
            levelCount=0;
        }
    }

    void checkLevelUp()
    {
        // Experience thresholds for level ups
        int expNeeded = 100 + 100 * pow(level, 2) * 0.3;
        if (exp >= expNeeded)
        {
            levelUP();
        }
    }
};


class Interface
{
public:
    Interface(sf::RenderWindow& win) : window(win)
    {
        if (!font.loadFromFile("C:/Users/piotr/OneDrive/Pulpit/projekt/arial.ttf"))
        {
            cerr << "Could not load font!" << endl;
        }

        setupText(playerHPText, "HP: ", 510, 20);
        setupText(playerATKText, "ATK: ", 510, 60);
        setupText(playerLCKText, "LCK: ", 510, 100);
        setupText(playerAGLText, "AGL: ", 510, 140);
        setupText(playerLevelText, "Level: ", 510, 180);
        setupText(playerEXPText, "EXP: ", 510, 220);
    }

    void displayStatus(Entity* player)
    {
        cout << "Player Status:" << endl;
        cout << "HP: " << player->getHP() << endl;
        cout << "ATK: " << player->getATK() << endl;
        cout << "LCK: " << player->getLCK() << endl;
        cout << "AGL: " << player->getAGL() << endl;
        cout << "Level: " << player->getLevel() << endl;
        cout << "Experience: " << player->getEXP() << endl;
    }

    void drawGUI(Entity* player)
    {
        updatePlayerStats(player);
        window.draw(playerHPText);
        window.draw(playerATKText);
        window.draw(playerLCKText);
        window.draw(playerAGLText);
        window.draw(playerLevelText);
        window.draw(playerEXPText);
    }

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text playerHPText;
    sf::Text playerATKText;
    sf::Text playerLCKText;
    sf::Text playerAGLText;
    sf::Text playerLevelText;
    sf::Text playerEXPText;

    void setupText(sf::Text& text, const string& str, float x, float y)
    {
        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(x, y);
    }

    void updatePlayerStats(Entity* player)
    {
        playerHPText.setString("HP: " + to_string(player->getHP()));
        playerATKText.setString("ATK: " + to_string(player->getATK()));
        playerLCKText.setString("LCK: " + to_string(player->getLCK()));
        playerAGLText.setString("AGL: " + to_string(player->getAGL()));
        playerLevelText.setString("Level: " + to_string(player->getLevel()));
        playerEXPText.setString("EXP: " + to_string(player->getEXP()));
    }
};

class Map
{
public:
    vector<vector<char>> generateMap(int rows, int cols)
    {
        vector<vector<char>> map(rows, vector<char>(cols, '.'));
        // Place some obstacles or landmarks randomly
        srand(time(nullptr));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (rand() % 10 == 0) // 10% chance to place an obstacle
                {
                    map[i][j] = '#';
                }
            }
        }
        return map;
    }

    void moveCharacter(vector<vector<char>>& map, int oldX, int oldY, int newX, int newY)
    {
        map[oldX][oldY] = '.'; // Clear old position
        map[newX][newY] = 'P'; // Place player in new position
    }

    bool checkTile(vector<vector<char>>& map, int x, int y)
    {
        return map[x][y] != '#'; // Return true if tile is not an obstacle
    }

    bool isEnemyTile(vector<vector<char>>& map, int x, int y)
    {
        return map[x][y] == 'E';
    }

    void clearTile(vector<vector<char>>& map, int x, int y)
    {
        map[x][y] = '.';
    }
};

class PlayerCharacter : public Entity
{
public:
    PlayerCharacter(int hp, int atk, int lck, int agl) : Entity(hp, atk, lck, agl) {}

    void gainEXP(int amount)
    {
        Entity::gainEXP(amount);
    }
    void refreshHP()
    {
        HP = getMaxHP(); // Assuming getMaxHP returns the maximum HP value for the player
    }
};

class Enemy : public Entity
{
public:
    enum Type { Goblin };

    Enemy() : Entity(20, 10, 20, 25), type(Goblin)
    {
        color = getColor(type);
    }

    Type getType() const { return type; }
    sf::Color getColor() const { return color; }

private:
    Type type;
    sf::Color color;

    sf::Color getColor(Type type)
    {
        switch (type)
        {
            case Goblin: return sf::Color::Green;
            default: return sf::Color::White;
        }
    }
};


class Game
{
public:
    Game() : window(sf::VideoMode(1000, 600), "SFML Game"), interface(window), player(100, 20, 10, 15),
             mapRows(10), mapCols(10), playerX(0), playerY(0), mapGenerationCount(0)
    {
        gameMap = map.generateMap(mapRows, mapCols);
        exploredMap = vector<vector<bool>>(mapRows, vector<bool>(mapCols, false));
        gameMap[playerX][playerY] = 'P';
        updateExploredTiles(playerX, playerY);
        spawnEnemies(5); // Initial spawn of enemies
    }

    void start()
    {
        startGame();
        mainLoop();
        endGame();
    }

private:
    sf::RenderWindow window;
    Interface interface;
    Map map;
    PlayerCharacter player;
    vector<vector<char>> gameMap;
    vector<vector<bool>> exploredMap;
    int mapRows;
    int mapCols;
    int playerX;
    int playerY;
    int mapGenerationCount; // Counter for how many maps have been generated
    vector<Enemy> enemies;

    void startGame()
    {
        cout << "Welcome to the Game! Let's start!" << endl;
    }

    void endGame()
    {
        cout << "Thanks for playing! Goodbye!" << endl;
    }

    void mainLoop()
    {
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                else if (event.type == sf::Event::KeyPressed)
                {
                    handleInput(event.key.code);
                }
            }

            window.clear();
            drawMap();

            interface.drawGUI(&player);
            window.display();
        }
    }


    void handleInput(sf::Keyboard::Key key)
    {
        int newX = playerX;
        int newY = playerY;

        // Determine new position based on key pressed
        if (key == sf::Keyboard::W) newX--;
        else if (key == sf::Keyboard::S) newX++;
        else if (key == sf::Keyboard::A) newY--;
        else if (key == sf::Keyboard::D) newY++;

        // Check if the new position is within bounds
        if (newX >= 0 && newX < mapRows && newY >= 0 && newY < mapCols)
        {
            // Check if the tile is accessible (not an obstacle)
            if (map.checkTile(gameMap, newX, newY))
            {
                // Check if the tile is an enemy
                if (map.isEnemyTile(gameMap, newX, newY))
                {
                    Enemy* enemy = getEnemyAt(newX, newY);
                    if (enemy)
                    {
                        handleCombat(&player, enemy);
                        if (enemy->getHP() <= 0)
                        {
                            map.clearTile(gameMap, newX, newY);
                            enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
                                                         [](const Enemy& e) { return e.getHP() <= 0; }), enemies.end());
                        }
                    }
                }

                // Move player to the new position on the map
                map.moveCharacter(gameMap, playerX, playerY, newX, newY);
                playerX = newX;
                playerY = newY;

                // Update explored tiles around the player's new position
                updateExploredTiles(playerX, playerY);
            }
        }
        else
        {
            // Player attempted to leave the map, regenerate the map
            regenerateMap();
        }
    }



    int spawnEnemies(int count)
    {
        enemies.clear(); // Clear existing enemies

        for (int i = 0; i < count; ++i)
        {
            enemies.emplace_back();
            // You can adjust enemy attributes here based on mapGenerationCount
            // For example:
            int newHP = 20 + 5 * mapGenerationCount; // Increase HP as map generation count increases
            int newATK = 10 + 2 * mapGenerationCount; // Increase ATK as map generation count increases
            int newLCK = 20;
            int newAGL = 25;

            enemies.back().HP = newHP;
            enemies.back().ATK = newATK;
            enemies.back().LCK = newLCK;
            enemies.back().AGL = newAGL;

        }

        // Place enemies on the map
        for (int i = 0; i < enemies.size(); ++i)
        {
            int x = rand() % mapRows;
            int y = rand() % mapCols;
            while (gameMap[x][y] != '.')
            {
                x = rand() % mapRows;
                y = rand() % mapCols;
            }
            gameMap[x][y] = 'E';
        }

        return count;
    }

    Enemy* getEnemyAt(int x, int y)
    {
        for (auto& enemy : enemies)
        {
            if (gameMap[x][y] == 'E')
            {
                return &enemy; // Return a pointer to the enemy found
            }
        }
        return nullptr; // Return nullptr if no enemy found at (x, y)
    }


    void handleCombat(PlayerCharacter* player, Enemy* enemy)
    {
        cout << "Combat started!" << endl;

        while (player->getHP() > 0 && enemy->getHP() > 0)
        {
            // Player attacks
            player->dealDMG(enemy);
            cout << "Player attacks!" << endl;

            if (enemy->getHP() <= 0)
            {
                cout << "Enemy defeated!" << endl;
                map.clearTile(gameMap, playerX, playerY);
                break;
            }

            // Enemy attacks
            enemy->dealDMG(player);
            cout << "Enemy attacks!" << endl;

            if (player->getHP() <= 0)
            {
                cout << "Player defeated!" << endl;
                displayLosingScreen();
                break;
            }
        }

        if (player->getHP() > 0)
        {
            player->gainEXP(50);
        }

        // Check if all enemies are defeated
        if (allEnemiesDefeated())
        {
            regenerateMap(); // Regenerate the map and respawn enemies
        }
    }

    bool allEnemiesDefeated()
    {
        return enemies.empty();
    }

    void regenerateMap()
    {
        // Increment map generation count
        mapGenerationCount++;

        // Regenerate map and reset game state
        gameMap = map.generateMap(mapRows, mapCols);
        exploredMap = vector<vector<bool>>(mapRows, vector<bool>(mapCols, false));

        // Reset player's position to a valid starting position on the new map
        playerX = 0;
        playerY = 0;
        gameMap[playerX][playerY] = 'P'; // Place player in the starting position

        // Update explored tiles around the player's starting position
        updateExploredTiles(playerX, playerY);
        player.refreshHP();
        spawnEnemies(5);
    }








    void displayLosingScreen()
    {
        sf::Font font;
        if (!font.loadFromFile("C:/Users/piotr/OneDrive/Pulpit/projekt/arial.ttf"))
        {
            cerr << "Could not load font!" << endl;
        }

        sf::Text losingText;
        losingText.setFont(font);
        losingText.setString("You have been defeated by the enemy!\nGame Over!");
        losingText.setCharacterSize(36);
        losingText.setFillColor(sf::Color::Red);
        losingText.setPosition(250, 250);

        window.clear();
        window.draw(losingText);
        window.display();

        sf::sleep(sf::seconds(3)); // Pause for 3 seconds before closing
        window.close();
    }



    void updateExploredTiles(int x, int y)
    {
        for (int i = x - 1; i <= x + 1; ++i)
        {
            for (int j = y - 1; j <= y + 1; ++j)
            {
                if (i >= 0 && i < mapRows && j >= 0 && j < mapCols)
                {
                    exploredMap[i][j] = true;
                }
            }
        }
    }

    void drawMap()
    {
        for (int i = 0; i < mapRows; ++i)
        {
            for (int j = 0; j < mapCols; ++j)
            {
                sf::RectangleShape tile(sf::Vector2f(50, 50));
                tile.setPosition(j * 50, i * 50);

                if (exploredMap[i][j])
                {
                    if (gameMap[i][j] == '#')
                    {
                        tile.setFillColor(sf::Color::Black);
                    }
                    else if (gameMap[i][j] == 'P')
                    {
                        tile.setFillColor(sf::Color::Green);
                    }
                    else if (gameMap[i][j] == 'E')
                    {
                        tile.setFillColor(getEnemyColorAt(i, j));
                    }
                    else
                    {
                        tile.setFillColor(sf::Color::White);
                    }
                }
                else
                {
                    tile.setFillColor(sf::Color(50, 50, 50)); // Dark gray for unexplored
                }

                window.draw(tile);
            }
        }
    }

    sf::Color getEnemyColorAt(int x, int y)
    {
        for (auto& enemy : enemies)
        {
            if (gameMap[x][y] == 'E')
            {
                return enemy.getColor();
            }
        }
        return sf::Color::White; // Default color if no enemy found
    }
};

int main()
{
    Game game;
    game.start();
    return 0;
}


