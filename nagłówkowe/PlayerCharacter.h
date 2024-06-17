#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "Entity.h"

/**
 * @brief The PlayerCharacter class represents the player-controlled character.
 */
class PlayerCharacter : public Entity
{
public:
    /**
     * @brief Constructs a PlayerCharacter object with initial attributes.
     * @param hp Initial health points.
     * @param atk Initial attack points.
     * @param lck Initial luck attribute.
     * @param agl Initial agility attribute.
     */
    PlayerCharacter(int hp, int atk, int lck, int agl);

    /**
     * @brief Overrides the gainEXP method to ensure proper handling in PlayerCharacter context.
     * @param amount Amount of experience points gained.
     */
    void gainEXP(int amount) override;

    /**
     * @brief Refreshes the player's health points to maximum.
     */
    void refreshHP();

    /**
     * @brief Overrides the levelUP method to increase specific attributes upon leveling up.
     */
    void levelUP() override;

private:
    /**
     * @brief Increases player's stats (HP, ATK, LCK, AGL) upon leveling up.
     */
    void increaseStats() override;
};

#endif // PLAYERCHARACTER_H