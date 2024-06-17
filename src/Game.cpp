#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(1000, 600), "SFML Game"), interface(window), player(100, 20, 10, 15),
               mapRows(10), mapCols(10), playerX(0), playerY(0), mapGenerationCount(0)
{
    // Constructor implementation
}

void Game::start()
{
    initializeGame();
    mainLoop();
}

void Game::initializeGame()
{
    std::cout << "Welcome to the Game! Let's start!" << std::endl;
    gameMap = map.generateMap(mapRows, mapCols);
    exploredMap = std::vector<std::vector<bool>>(mapRows, std::vector<bool>(mapCols, false));
    gameMap[playerX][playerY] = 'P';
    // Initial setup of player and enemies
    player.refreshHP();
    spawnEnemies(5);
}

void Game::mainLoop()
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

void Game::handleInput(sf::Keyboard::Key keyCode)
{
    // Handle player movement or other input events
    switch (keyCode)
    {
        case sf::Keyboard::Up:
            // Handle up key press
            break;
        case sf::Keyboard::Down:
            // Handle down key press
            break;
        case sf::Keyboard::Left:
            // Handle left key press
            break;
        case sf::Keyboard::Right:
            // Handle right key press
            break;
        default:
            break;
    }
}

void Game::spawnEnemies(int count)
{
    // Generate enemies and place them on the map
    srand(time(nullptr));
    for (int i = 0; i < count; ++i)
    {
        int x = rand() % mapRows;
        int y = rand() % mapCols;
        if (gameMap[x][y] == '.') // Check if tile is empty
        {
            gameMap[x][y] = 'E'; // Place enemy
            enemies.emplace_back(); // Add enemy to vector
        }
    }
}

void Game::handleCombat(Enemy& enemy)
{
    // Handle combat between player and enemy
    // Example: player.dealDMG(&enemy);
}

void Game::regenerateMap()
{
    // Regenerate game map with new obstacles and enemies
    ++mapGenerationCount;
    gameMap = map.generateMap(mapRows, mapCols);
    exploredMap = std::vector<std::vector<bool>>(mapRows, std::vector<bool>(mapCols, false));
    playerX = 0;
    playerY = 0;
    gameMap[playerX][playerY] = 'P';
    spawnEnemies(5);
}

void Game::drawMap()
{
    // Draw game map on the SFML window
    // Example: draw tiles based on gameMap, draw enemies, draw player character
    // Using SFML drawing functions
}
