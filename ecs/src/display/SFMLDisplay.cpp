/**
 * @file SFMLDisplay.hpp
 * @brief A class for managing display using SFML (Simple and Fast Multimedia Library).
 *
 * This class handles the creation of a render window, event management,
 * drawing textures, and handling keyboard input for the display.
 */

#ifndef SFML_DISPLAY_HPP
#define SFML_DISPLAY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ITexture.hpp"

namespace display {

/**
 * @class SFMLDisplay
 * @brief Manages the SFML rendering window and input.
 *
 * The SFMLDisplay class provides methods for initializing the display,
 * updating the window, clearing the window, drawing textures, and
 * checking keyboard input.
 */
class SFMLDisplay {
public:
    /**
     * @brief Constructs an SFMLDisplay object.
     *
     * Initializes the key bindings for keyboard input.
     */
    SFMLDisplay();

    /**
     * @brief Destroys the SFMLDisplay object.
     *
     * Cleans up the resources used by the display.
     */
    ~SFMLDisplay();

    /**
     * @brief Initializes the render window.
     *
     * @param width The width of the window.
     * @param height The height of the window.
     * @param title The title of the window.
     */
    void init(int width, int height, const std::string &title);

    /**
     * @brief Updates the display and processes events.
     *
     * Polls for events and updates the window.
     */
    void update();

    /**
     * @brief Clears the window for rendering.
     */
    void clear();

    /**
     * @brief Checks if the window is open.
     *
     * @return True if the window is open, false otherwise.
     */
    bool isOpen() const;

    /**
     * @brief Closes the render window.
     */
    void close();

    /**
     * @brief Draws a texture at the specified position.
     *
     * @param texture A shared pointer to the texture to draw.
     * @param x The x-coordinate for the texture position.
     * @param y The y-coordinate for the texture position.
     */
    void draw(std::shared_ptr<ITexture> &texture, float x, float y);

    /**
     * @brief Checks if a specific key is pressed.
     *
     * @param key The key to check.
     * @return True if the key is pressed, false otherwise.
     */
    bool isKeyPressed(Key key) const;

    /**
     * @brief Checks if a specific key is released.
     *
     * @param key The key to check.
     * @return True if the key is released, false otherwise.
     */
    bool isKeyReleased(Key key) const;

    /**
     * @brief Creates a texture from a file path.
     *
     * @param path The file path of the texture.
     * @return A shared pointer to the created texture.
     */
    std::shared_ptr<ITexture> createTexture(const std::string &path);

private:
    sf::RenderWindow *m_window;  ///< Pointer to the SFML render window.
    std::vector<sf::Keyboard::Key> m_keys;  ///< List of keys for input management.
};

} // namespace display

#endif // SFML_DISPLAY_HPP
