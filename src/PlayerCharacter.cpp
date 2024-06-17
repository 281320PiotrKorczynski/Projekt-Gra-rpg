#include "PlayerCharacter.h"
#include <iostream>

PlayerCharacter::PlayerCharacter(int hp, int atk, int lck, int agl) : Entity(hp, atk, lck, agl)
{
    // Constructor implementation
}

void PlayerCharacter::gainEXP(int amount)
{
    Entity::gainEXP(amount); // Call base class method
    std::cout << "Player gained " << amount << " experience points!" << std::endl;
}

void PlayerCharacter::refreshHP()
{
    // Restore player's health points to maximum
    HP = getMaxHP();
}

void PlayerCharacter::levelUP()
{
    Entity::levelUP(); // Call base class method
    std::cout << "Level Up! Player reached level " << getLevel() << "!" << std::endl;
}

void PlayerCharacter::increaseStats()
{
    // Implement specific logic to increase player's stats upon level up
    // For example:
    HP += 10;
    ATK += 5;
    LCK += 3;
    AGL += 2;
}
