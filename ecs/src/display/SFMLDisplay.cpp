/**
 * @file SFMLDisplay.hpp
 * @brief This file defines the SFMLDisplay class, which handles rendering and input using SFML.
 */

#include "display/SFMLDisplay.hpp"
#include <iostream>

namespace display
{

/**
 * @brief Constructs the SFMLDisplay object.
 *
 * Initializes the keys that can be used for user input.
 */
SFMLDisplay::SFMLDisplay()
{
    m_keys.push_back(sf::Keyboard::Key::Up);
    m_keys.push_back(sf::Keyboard::Key::Down);
    m_keys.push_back(sf::Keyboard::Key::Left);
    m_keys.push_back(sf::Keyboard::Key::Right);
    m_keys.push_back(sf::Keyboard::Key::Space);
}

/**
 * @brief Destroys the SFMLDisplay object.
 *
 * Cleans up resources used by the display window.
 */
SFMLDisplay::~SFMLDisplay()
{
    delete m_window;
}

/**
 * @brief Initializes the display window.
 *
 * @param width The width of the window.
 * @param height The height of the window.
 * @param title The title of the window.
 */
void SFMLDisplay::init(int width, int height, const std::string &title)
{
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

/**
 * @brief Updates the display, polling for events.
 *
 * Closes the window if the close event is triggered.
 */
void SFMLDisplay::update()
{
    sf::Event event;
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
    }
    m_window->display();
}

/**
 * @brief Clears the window for the next frame.
 */
void SFMLDisplay::clear()
{
    m_window->clear();
}

/**
 * @brief Checks if the window is open.
 *
 * @return True if the window is open, false otherwise.
 */
bool SFMLDisplay::isOpen() const
{
    return m_window->isOpen();
}

/**
 * @brief Closes the display window.
 */
void SFMLDisplay::close()
{
    m_window->close();
}

/**
 * @brief Draws a texture at a specified position.
 *
 * @param texture A shared pointer to the texture to be drawn.
 * @param x The x-coordinate where the texture will be drawn.
 * @param y The y-coordinate where the texture will be drawn.
 */
void SFMLDisplay::draw(std::shared_ptr<ITexture> &texture, float x, float y)
{
    auto &sfmlTexture = static_cast<SFMLTexture &>(*texture);

    sfmlTexture.sprite.setPosition(x, y);

    m_window->draw(sfmlTexture.sprite);
}

/**
 * @brief Checks if a specified key is currently pressed.
 *
 * @param key The key to check.
 * @return True if the key is pressed, false otherwise.
 */
bool SFMLDisplay::isKeyPressed(Key key) const
{
    return sf::Keyboard::isKeyPressed(m_keys[key]);
}

/**
 * @brief Checks if a specified key is currently released.
 *
 * @param key The key to check.
 * @return True if the key is released, false otherwise.
 */
bool SFMLDisplay::isKeyReleased(Key key) const
{
    return !sf::Keyboard::isKeyPressed(m_keys[key]);
}

/**
 * @brief Creates a texture from a specified file path.
 *
 * @param path The file path to the texture.
 * @return A shared pointer to the created texture.
 */
std::shared_ptr<ITexture> SFMLDisplay::createTexture(const std::string &path)
{
    return std::make_shared<SFMLTexture>(path);
}

}
