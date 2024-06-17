#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

/**
 * @brief The Interface class manages the graphical user interface (GUI) elements.
 */
class Interface
{
public:
    /**
     * @brief Constructs an Interface object, initializing GUI elements.
     * @param win Reference to the SFML RenderWindow for rendering.
     */
    Interface(sf::RenderWindow& win);

    /**
     * @brief Displays the current status of the player entity in the console.
     * @param player Pointer to the PlayerCharacter object whose status is to be displayed.
     */
    void displayStatus(Entity* player);

    /**
     * @brief Draws the GUI elements representing player stats on the game window.
     * @param player Pointer to the PlayerCharacter object whose stats are to be displayed.
     */
    void drawGUI(Entity* player);

private:
    sf::RenderWindow& window; ///< Reference to the SFML RenderWindow for rendering.
    sf::Font font; ///< SFML Font object for text rendering.
    sf::Text playerHPText; ///< SFML Text object for displaying player's health points.
    sf::Text playerATKText; ///< SFML Text object for displaying player's attack points.
    sf::Text playerLCKText; ///< SFML Text object for displaying player's luck attribute.
    sf::Text playerAGLText; ///< SFML Text object for displaying player's agility attribute.
    sf::Text playerLevelText; ///< SFML Text object for displaying player's level.
    sf::Text playerEXPText; ///< SFML Text object for displaying player's experience points.

    /**
     * @brief Sets up a text element with given parameters such as position and content.
     * @param text Reference to the SFML Text object to be set up.
     * @param str String content of the text.
     * @param x X-coordinate position of the text.
     * @param y Y-coordinate position of the text.
     */
    void setupText(sf::Text& text, const std::string& str, float x, float y);

    /**
     * @brief Updates the displayed player stats based on the current state of the player entity.
     * @param player Pointer to the PlayerCharacter object whose stats are to be updated.
     */
    void updatePlayerStats(Entity* player);
};

#endif // INTERFACE_H
