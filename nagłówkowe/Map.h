#ifndef MAP_H
#define MAP_H

#include <vector>

/**
 * @brief The Map class handles generation and manipulation of the game map.
 */
class Map
{
public:
    /**
     * @brief Generates a game map with specified dimensions and places obstacles randomly.
     * @param rows Number of rows in the map.
     * @param cols Number of columns in the map.
     * @return 2D vector representing the generated map.
     */
    std::vector<std::vector<char>> generateMap(int rows, int cols);

    /**
     * @brief Moves a character on the map from old position to new position.
     * @param map Reference to the 2D vector representing the map.
     * @param oldX Old X-coordinate of the character.
     * @param oldY Old Y-coordinate of the character.
     * @param newX New X-coordinate of the character.
     * @param newY New Y-coordinate of the character.
     */
    void moveCharacter(std::vector<std::vector<char>>& map, int oldX, int oldY, int newX, int newY);

    /**
     * @brief Checks if a tile on the map is accessible (not an obstacle).
     * @param map Reference to the 2D vector representing the map.
     * @param x X-coordinate of the tile to check.
     * @param y Y-coordinate of the tile to check.
     * @return True if the tile is accessible, false otherwise.
     */
    bool checkTile(std::vector<std::vector<char>>& map, int x, int y);

    /**
     * @brief Checks if a tile on the map contains an enemy character.
     * @param map Reference to the 2D vector representing the map.
     * @param x X-coordinate of the tile to check.
     * @param y Y-coordinate of the tile to check.
     * @return True if the tile contains an enemy, false otherwise.
     */
    bool isEnemyTile(std::vector<std::vector<char>>& map, int x, int y);

    /**
     * @brief Clears the tile on the map at specified coordinates.
     * @param map Reference to the 2D vector representing the map.
     * @param x X-coordinate of the tile to clear.
     * @param y Y-coordinate of the tile to clear.
     */
    void clearTile(std::vector<std::vector<char>>& map, int x, int y);
};

#endif // MAP_H
