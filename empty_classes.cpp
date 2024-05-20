#include <iostream>
#include <string>
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
        cout << "Leveling up! Current level: " << level << endl;
    }

private:
    int HP;
    int ATK;
    int LCK;
    int AGL;
    int level;
    int exp;

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

// Forward declaration
class Interface;

class Game
{
public:
    void startGame()
    {
        cout << "Welcome to the Game! Let's start!" << endl;
    }

    void endGame()
    {
        cout << "Thanks for playing! Goodbye!" << endl;
    }
};

class Interface
{
public:
    void displayMap(const vector<vector<char>>& map)
    {
        cout << "Map displayed:" << endl;
        for (const auto& row : map)
        {
            for (char tile : row)
            {
                cout << tile << " ";
            }
            cout << endl;
        }
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

    char inputSignal()
    {
        char input;
        cout << "Enter your move (W, A, S, D): ";
        cin >> input;
        return input;
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
};

class PlayerCharacter : public Entity
{
public:
    PlayerCharacter(int hp, int atk, int lck, int agl) : Entity(hp, atk, lck, agl) {}

    void gainEXP(int amount)
    {
        Entity::gainEXP(amount);
    }
};

class Enemy : public Entity
{
public:
    Enemy(int hp, int atk, int lck, int agl) : Entity(hp, atk, lck, agl) {}
};

int main()
{
    Game game;
    Interface interface;
    Map map;

    game.startGame();

    const int mapSize = 5;
    vector<vector<char>> gameMap = map.generateMap(mapSize, mapSize);

    PlayerCharacter player(100, 20, 10, 15);
    Enemy enemy(50, 10, 5, 8);

    interface.displayMap(gameMap);
    interface.displayStatus(&player);

    char move = interface.inputSignal();
    int playerX = 0, playerY = 0; // Player's initial position
    while (move != 'q') // 'q' to quit
    {
        int newX = playerX, newY = playerY;
        switch (move)
        {
            case 'W':
            case 'w':
                newX--;
                break;
            case 'S':
            case 's':
                newX++;
                break;
            case 'A':
            case 'a':
                newY--;
                break;
            case 'D':
            case 'd':
                newY++;
                break;
        }
        if (map.checkTile(gameMap, newX, newY))
        {
            map.moveCharacter(gameMap, playerX, playerY, newX, newY);
            playerX = newX;
            playerY = newY;
        }
        else
        {
            cout << "Cannot move there! Obstacle in the way!" << endl;
        }

        interface.displayMap(gameMap);
        interface.displayStatus(&player);

        move = interface.inputSignal();
    }

    game.endGame();

    return 0;
}
