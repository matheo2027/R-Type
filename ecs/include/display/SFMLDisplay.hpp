/**
 * @file SFMLDisplay.hpp
 * @brief Header file for SFMLDisplay and SFMLTexture classes.
 *
 * This file contains the declaration of the SFMLTexture struct and the SFMLDisplay class,
 * which are used for rendering graphics in a window using the SFML library.
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <string>
#include <memory>

#include "IDisplay.hpp"

namespace display
{

/**
 * @struct SFMLTexture
 * @brief Represents a texture and its corresponding sprite in SFML.
 *
 * The SFMLTexture struct inherits from the ITexture interface and encapsulates
 * the SFML texture and sprite. It is responsible for loading a texture from a file
 * and creating a sprite that can be drawn on the screen.
 */
struct SFMLTexture : public ITexture
{
    /**
     * @brief Constructs an SFMLTexture with the specified file path.
     *
     * @param path The file path to the texture image.
     */
    SFMLTexture(const std::string &path) : ITexture(path)
    {
        texture.loadFromFile(path);
        sprite.setTexture(texture);
    }

    /**
     * @brief Destructor for SFMLTexture.
     */
    ~SFMLTexture() override = default;

    sf::Texture texture; /**< The SFML texture. */
    sf::Sprite sprite;   /**< The SFML sprite associated with the texture. */
};

/**
 * @class SFMLDisplay
 * @brief Handles the display and rendering using the SFML library.
 *
 * The SFMLDisplay class inherits from the IDisplay interface and provides methods
 * to initialize the window, update the display, handle input, and draw textures.
 */
class SFMLDisplay : public IDisplay
{
    public:
        /**
         * @brief Default constructor for SFMLDisplay.
         */
        SFMLDisplay();

        /**
         * @brief Destructor for SFMLDisplay.
         */
        ~SFMLDisplay() override;

        /**
         * @brief Initializes the display with the given width, height, and title.
         *
         * @param width The width of the display window.
         * @param height The height of the display window.
         * @param title The title of the display window.
         */
        void init(int width, int height, const std::string &title) override;

        /**
         * @brief Updates the display for the current frame.
         */
        void update() override;

        /**
         * @brief Clears the display window.
         */
        void clear() override;

        /**
         * @brief Checks if the display window is open.
         *
         * @return True if the window is open; otherwise, false.
         */
        bool isOpen() const override;

        /**
         * @brief Closes the display window.
         */
        void close() override;

        /**
         * @brief Draws the specified texture at the given position.
         *
         * @param texture The texture to draw.
         * @param x The x-coordinate to draw the texture.
         * @param y The y-coordinate to draw the texture.
         */
        void draw(std::shared_ptr<ITexture> &texture, float x, float y) override;

        /**
         * @brief Checks if a specific key is currently pressed.
         *
         * @param key The key to check.
         * @return True if the key is pressed; otherwise, false.
         */
        bool isKeyPressed(Key key) const override;

        /**
         * @brief Checks if a specific key was released.
         *
         * @param key The key to check.
         * @return True if the key is released; otherwise, false.
         */
        bool isKeyReleased(Key key) const override;

        /**
         * @brief Creates a texture from a file.
         *
         * @param path The file path to the texture image.
         * @return A shared pointer to the created texture.
         */
        std::shared_ptr<ITexture> createTexture(const std::string &path);

    private:
        std::vector<sf::Keyboard::Key> m_keys; /**< Vector storing the state of keyboard keys. */
        sf::RenderWindow *m_window; /**< Pointer to the SFML window. */
};

}
