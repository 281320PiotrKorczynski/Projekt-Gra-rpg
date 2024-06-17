#include "Map.h"
#include <cstdlib>
#include <ctime>

std::vector<std::vector<char>> Map::generateMap(int rows, int cols)
{
    std::vector<std::vector<char>> map(rows, std::vector<char>(cols, '.'));

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

void Map::moveCharacter(std::vector<std::vector<char>>& map, int oldX, int oldY, int newX, int newY)
{
    map[oldX][oldY] = '.'; // Clear old position
    map[newX][newY] = 'P'; // Place player in new position
}

bool Map::checkTile(std::vector<std::vector<char>>& map, int x, int y)
{
    return map[x][y] != '#'; // Return true if tile is not an obstacle
}

bool Map::isEnemyTile(std::vector<std::vector<char>>& map, int x, int y)
{
    return map[x][y] == 'E';
}

void Map::clearTile(std::vector<std::vector<char>>& map, int x, int y)
{
    map[x][y] = '.';
}
