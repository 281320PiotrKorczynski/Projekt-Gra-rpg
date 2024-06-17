#ifndef ENTITY_H
#define ENTITY_H

/**
 * @brief The Entity class represents a generic game entity with attributes and methods.
 */
class Entity
{
public:
    /**
     * @brief Constructs an Entity object with given initial attributes.
     * @param hp Initial health points.
     * @param atk Initial attack points.
     * @param lck Initial luck attribute.
     * @param agl Initial agility attribute.
     */
    Entity(int hp, int atk, int lck, int agl);

    // Methods
    /**
     * @brief Returns the current health points of the entity.
     * @return Current health points.
     */
    int getHP() const;

    /**
     * @brief Returns the attack points of the entity.
     * @return Attack points.
     */
    int getATK() const;

    // Other getters for attributes (LCK, AGL, level, exp)...

    /**
     * @brief Calculates and returns the maximum health points based on the entity's level.
     * @return Maximum health points.
     */
    int getMaxHP() const;

    /**
     * @brief Deals damage to a target entity based on attack points and luck factor.
     * @param target Pointer to the target Entity object.
     */
    void dealDMG(Entity* target);

    /**
     * @brief Takes damage and reduces health points accordingly.
     * @param damage Amount of damage to be taken.
     */
    void takeDMG(int damage);

    /**
     * @brief Increases entity's experience points and checks for level up.
     * @param amount Amount of experience points gained.
     */
    void gainEXP(int amount);

    /**
     * @brief Levels up the entity, increasing its attributes and displaying level up message.
     */
    void levelUP();

    // Other methods (increaseStats, checkLevelUp)...

    /**
     * @brief Virtual method to be overridden by derived classes to increase specific stats upon level up.
     */
    virtual void increaseStats();

private:
    // Member variables (HP, ATK, LCK, AGL, level, exp)...
};

#endif // ENTITY_H