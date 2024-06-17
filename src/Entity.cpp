#include "Entity.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

Entity::Entity(int hp, int atk, int lck, int agl) : HP(hp), ATK(atk), LCK(lck), AGL(agl), level(1), exp(0)
{
    // Constructor implementation
}

int Entity::getHP() const
{
    return HP;
}

int Entity::getATK() const
{
    return ATK;
}

// Implementations of other methods (getLCK, getAGL, getMaxHP, dealDMG, takeDMG, gainEXP, levelUP, increaseStats, checkLevelUp)...
