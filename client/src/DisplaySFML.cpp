/**
 * @file DisplaySFML.hpp
 * @brief Header file for the DisplaySFML class, which handles rendering using SFML.
 */

#ifndef DISPLAY_SFML_HPP
#define DISPLAY_SFML_HPP

#include <SFML/Graphics.hpp>
#include "IDisplay.hpp"

/**
 * @namespace gfx
 * @brief The namespace for the graphics-related classes.
 */
namespace gfx
{
    /**
     * @class DisplaySFML
     * @brief A class that implements the IDisplay interface using the SFML library for rendering graphics.
     *
     * This class manages the creation and handling of an SFML window, including drawing textures and text,
     * and handling input events.
     */
    class DisplaySFML : public IDisplay
    {
    public:
        /**
         * @brief Constructs a DisplaySFML object.
         * @param width The width of the window.
         * @param height The height of the window.
         * @param title The title of the window.
         */
        DisplaySFML(u32 width, u32 height, std::string &title);

        /**
         * @brief Updates the window display.
         */
        void update() override;

        /**
         * @brief Clears the window.
         */
        void clear() override;

        /**
         * @brief Checks if the window is currently open.
         * @return True if the window is open, false otherwise.
         */
        bool isRunning() const override;

        /**
         * @brief Closes the window.
         */
        void close() override;

        /**
         * @brief Draws a texture at the specified position.
         * @param texture The texture to draw.
         * @param x The x-coordinate for the position.
         * @param y The y-coordinate for the position.
         */
        void draw(const ITexture &texture, u32 x, u32 y) override;

        /**
         * @brief Draws text at the specified position.
         * @param text The text to draw.
         * @param x The x-coordinate for the position.
         * @param y The y-coordinate for the position.
         */
        void draw(const std::string &text, u32 x, u32 y) override;

        /**
         * @brief Checks if a specific key is pressed.
         * @param key The key to check, represented by its constant value.
         * @return True if the key is pressed, false otherwise.
         */
        bool getKeyDown(u8 key) const override;

    private:
        sf::RenderWindow m_window; ///< The SFML window object.
    };

} // namespace gfx

#endif // DISPLAY_SFML_HPP
