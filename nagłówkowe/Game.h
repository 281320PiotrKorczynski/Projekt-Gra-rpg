#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Interface.h"
#include "Map.h"
#include "Enemy.h"

/**
 * @brief The Game class manages the main game loop, window, entities, map, and interactions.
 */
class Game
{
public:
    /**
     * @brief Constructs a Game object, initializing game window, entities, map, etc.
     */
    Game();

    /**
     * @brief Starts the game loop and handles game events.
     */
    void start();

private:
    sf::RenderWindow window; ///< SFML window object for rendering.
    Interface interface; ///< Interface object for displaying game UI.
    Map map; ///< Map object for managing game map.
    PlayerCharacter player; ///< PlayerCharacter object representing the player entity.
    std::vector<std::vector<char>> gameMap; ///< 2D vector representing the game map.
    std::vector<std::vector<bool>> exploredMap; ///< 2D vector representing explored map tiles.
    int mapRows; ///< Number of rows in the game map.
    int mapCols; ///< Number of columns in the game map.
    int playerX; ///< Current X position of the player on the map.
    int playerY; ///< Current Y position of the player on the map.
    int mapGenerationCount; ///< Counter for number of map generations.
    std::vector<Enemy> enemies; ///< Vector containing Enemy objects representing enemies in the game.

    /**
     * @brief Initializes the game state, including map generation, player initialization, and initial enemy spawn.
     */
    void initializeGame();

    /**
     * @brief Main game loop that processes events, updates game state, and renders the game.
     */
    void mainLoop();

    // Other private methods for handling input, drawing map, handling combat, regenerating map, etc.
};

#endif // GAME_H
