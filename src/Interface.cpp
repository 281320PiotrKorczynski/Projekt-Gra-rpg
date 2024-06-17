#include "Interface.h"
#include <iostream>

Interface::Interface(sf::RenderWindow& win) : window(win)
{
    if (!font.loadFromFile("C:/Users/piotr/OneDrive/Pulpit/projekt/arial.ttf"))
    {
        std::cerr << "Could not load font!" << std::endl;
    }

    setupText(playerHPText, "HP: ", 510, 20);
    setupText(playerATKText, "ATK: ", 510, 60);
    setupText(playerLCKText, "LCK: ", 510, 100);
    setupText(playerAGLText, "AGL: ", 510, 140);
    setupText(playerLevelText, "Level: ", 510, 180);
    setupText(playerEXPText, "EXP: ", 510, 220);
}

void Interface::displayStatus(Entity* player)
{
    std::cout << "Player Status:" << std::endl;
    std::cout << "HP: " << player->getHP() << std::endl;
    std::cout << "ATK: " << player->getATK() << std::endl;
    std::cout << "LCK: " << player->getLCK() << std::endl;
    std::cout << "AGL: " << player->getAGL() << std::endl;
    std::cout << "Level: " << player->getLevel() << std::endl;
    std::cout << "Experience: " << player->getEXP() << std::endl;
}

void Interface::drawGUI(Entity* player)
{
    updatePlayerStats(player);
    window.draw(playerHPText);
    window.draw(playerATKText);
    window.draw(playerLCKText);
    window.draw(playerAGLText);
    window.draw(playerLevelText);
    window.draw(playerEXPText);
}

void Interface::setupText(sf::Text& text, const std::string& str, float x, float y)
{
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
}

void Interface::updatePlayerStats(Entity* player)
{
    playerHPText.setString("HP: " + std::to_string(player->getHP()));
    playerATKText.setString("ATK: " + std::to_string(player->getATK()));
    playerLCKText.setString("LCK: " + std::to_string(player->getLCK()));
    playerAGLText.setString("AGL: " + std::to_string(player->getAGL()));
    playerLevelText.setString("Level: " + std::to_string(player->getLevel()));
    playerEXPText.setString("EXP: " + std::to_string(player->getEXP()));
}
