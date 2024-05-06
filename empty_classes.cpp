#include <iostream>

using namespace std;
int main()
{

}


class Game
{
    public:
    void startGame()
    {

    }

    void endGame()
    {
        
    }
};

class Interface
{
    public:
    void displayMap()
    {

    }

    void displayStatus()
    {

    }

    void inputSignal()
    {

    }
};

class Map
{
    public:
    void generateMap()
    {

    }

    void spawnEnemies()
    {

    }

    void randomEvents()
    {

    }

    void moveCharacter()
    {

    }

    void checkTile()
    {

    }
};
class Entity
{
    public:
    int HP;
    int ATK;
    int LCK;
    int AGL;
    void dealDMG()
    {

    }

    private:
    void death()
    {

    }

};

class PlayerCharacter
:public Entity
{
    private:
    string charachter_class;
    int exp_amount;

    public:
    void gainEXP()
    {

    }

    void levelUP()
    {

    }
};

class Enemy
:public Entity
{
    public:
    string enemy_type;

    private:
    void uniqueTrait()
    {

    }

    void uniqueLoot()
    {

    }
};