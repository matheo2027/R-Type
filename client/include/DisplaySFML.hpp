/**
 * @file DisplaySFML.hpp
 * @brief Declaration of the DisplaySFML class, an implementation of the IDisplay interface using the SFML library.
 */

#pragma once
#include "IDisplay.hpp"
#include <SFML/Graphics.hpp>

namespace gfx
{
/**
 * @class DisplaySFML
 * @brief An implementation of the IDisplay interface, responsible for handling rendering and input using SFML.
 *
 * The DisplaySFML class provides methods for initializing, updating, clearing the screen,
 * drawing textures and text, handling input, and managing the display window.
 */
class DisplaySFML : public IDisplay
{
public:
    /**
     * @brief Constructs a new DisplaySFML object.
     * @param width The width of the display window.
     * @param height The height of the display window.
     * @param title The title of the display window.
     */
    DisplaySFML(u32 width, u32 height, std::string &title);

    /**
     * @brief Updates the display window, processing any pending events.
     */
    void update() override;

    /**
     * @brief Clears the display window, preparing it for new drawing operations.
     */
    void clear() override;

    /**
     * @brief Checks if the display window is still running.
     * @return True if the display window is open, otherwise false.
     */
    bool isRunning() const override;

    /**
     * @brief Closes the display window.
     */
    void close() override;

    /**
     * @brief Draws a texture at the specified coordinates.
     * @param texture The texture to be drawn.
     * @param x The x-coordinate of the position.
     * @param y The y-coordinate of the position.
     */
    void draw(const ITexture &texture, u32 x, u32 y) override;

    /**
     * @brief Draws text at the specified coordinates.
     * @param text The text to be drawn.
     * @param x The x-coordinate of the position.
     * @param y The y-coordinate of the position.
     */
    void draw(const std::string &text, u32 x, u32 y) override;

    /**
     * @brief Checks if a specific key is pressed down.
     * @param key The key to check.
     * @return True if the key is pressed, otherwise false.
     */
    bool getKeyDown(u8 key) const override;

    /**
     * @brief The SFML RenderWindow used for rendering and managing the window.
     */
    sf::RenderWindow m_window;
};
}
