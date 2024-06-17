#include "Enemy.h"

Enemy::Enemy() : Entity(20, 10, 20, 25), type(Goblin)
{
    color = getColor(type);
}

Enemy::Type Enemy::getType() const
{
    return type;
}

sf::Color Enemy::getColor() const
{
    return color;
}

sf::Color Enemy::getColor(Type type)
{
    switch (type)
    {
        case Goblin: return sf::Color::Green;
        default: return sf::Color::White;
    }
}
