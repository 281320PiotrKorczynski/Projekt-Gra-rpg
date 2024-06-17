#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

/**
 * @brief The Enemy class represents an enemy entity with specific attributes and behavior.
 */
class Enemy : public Entity
{
public:
    /**
     * @brief Enum defining types of enemies.
     */
    enum Type { Goblin };

    /**
     * @brief Constructs an Enemy object of a specific type with default attributes.
     */
    Enemy();

    /**
     * @brief Gets the type of the enemy.
     * @return Type of the enemy.
     */
    Type getType() const;

    /**
     * @brief Gets the color associated with the enemy type.
     * @return Color of the enemy.
     */
    sf::Color getColor() const;

private:
    Type type; ///< Type of the enemy.
    sf::Color color; ///< Color associated with the enemy type.

    /**
     * @brief Gets the color based on the enemy type.
     * @param type Type of the enemy.
     * @return Color associated with the enemy type.
     */
    sf::Color getColor(Type type);
};

#endif // ENEMY_H
