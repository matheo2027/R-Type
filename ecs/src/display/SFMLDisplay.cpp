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
    m_keys.push_back(sf::Keyboard::Key::C);

    m_mouse.push_back(sf::Mouse::Button::Left);
    m_mouse.push_back(sf::Mouse::Button::Right);
    m_mouse.push_back(sf::Mouse::Button::Middle);
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
    m_renderTexture.create(width, height);
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

    m_renderTexture.display();
    sf::Sprite sprite(m_renderTexture.getTexture());

    if (m_colorBlindness != ColorBlindness::NONE) {
        m_shader.setUniform("texture", m_renderTexture.getTexture());
        m_window->draw(sprite, &m_shader);
    } else {
        m_window->draw(sprite);
    }

    m_window->display();
}

/**
 * @brief Clears the window for the next frame.
 */
void SFMLDisplay::clear()
{
    m_window->clear();
    m_renderTexture.clear();
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

    m_renderTexture.draw(sfmlTexture.sprite);
}

/**
 * @brief Checks if a specified key is currently pressed.
 *
 * @param key The key to check.
 * @return True if the key is pressed, false otherwise.
 */
bool SFMLDisplay::isKeyPressed(Key key) const
{
    if (m_window->hasFocus()) {
        return sf::Keyboard::isKeyPressed(m_keys[key]);
    }

    return false;
}

/**
 * @brief Checks if a specified key is currently released.
 *
 * @param key The key to check.
 * @return True if the key is released, false otherwise.
 */
bool SFMLDisplay::isKeyReleased(Key key) const
{
    if (m_window->hasFocus()) {
        return !sf::Keyboard::isKeyPressed(m_keys[key]);
    }

    return false;
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

/**
 * @brief Checks if a specified mouse button is currently pressed.
 *
 * @param button The mouse button to check.
 * @return True if the mouse button is pressed, false otherwise.
 */
bool SFMLDisplay::isMouseButtonPressed(MouseButton button) const
{
    return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
}

/**
 * @brief Gets the current position of the mouse.
 *
 * @param x The x-coordinate of the mouse.
 * @param y The y-coordinate of the mouse.
 */
void SFMLDisplay::getMousePosition(float &x, float &y) const
{
    auto pos = sf::Mouse::getPosition(*m_window);
    x = pos.x;
    y = pos.y;
}

void SFMLDisplay::setColorBlindness(ColorBlindness mode)
{
    m_colorBlindness = mode;

    const std::string shaderCode = R"(
        uniform sampler2D texture;
        uniform float matrix[9];

        void main()
        {
            vec4 color = texture2D(texture, gl_TexCoord[0].xy);
            vec3 newColor = vec3(0.0);

            newColor.r = dot(color.rgb, vec3(matrix[0], matrix[1], matrix[2]));
            newColor.g = dot(color.rgb, vec3(matrix[3], matrix[4], matrix[5]));
            newColor.b = dot(color.rgb, vec3(matrix[6], matrix[7], matrix[8]));

            gl_FragColor = vec4(newColor, color.a);
        }
    )";

    if (!m_shader.loadFromMemory(shaderCode, sf::Shader::Fragment)) {
        throw std::runtime_error("Failed to load shader");
    }

    float matrix[9] = {0.0f};
    switch (mode) {
        case ColorBlindness::PROTANOPIA:
            matrix[0] = 0.567f;
            matrix[1] = 0.433f;
            matrix[2] = 0.0f;
            matrix[3] = 0.558f;
            matrix[4] = 0.442f;
            matrix[5] = 0.0f;
            matrix[6] = 0.0f;
            matrix[7] = 0.242f;
            matrix[8] = 0.758f;
            break;

        case ColorBlindness::DEUTERANOPIA:
            matrix[0] = 0.625f;
            matrix[1] = 0.375f;
            matrix[2] = 0.0f;
            matrix[3] = 0.7f;
            matrix[4] = 0.3f;
            matrix[5] = 0.0f;
            matrix[6] = 0.0f;
            matrix[7] = 0.3f;
            matrix[8] = 0.7f;
            break;

        case ColorBlindness::TRITANOPIA:
            matrix[0] = 0.95f;
            matrix[1] = 0.05f;
            matrix[2] = 0.0f;
            matrix[3] = 0.0f;
            matrix[4] = 0.433f;
            matrix[5] = 0.567f;
            matrix[6] = 0.0f;
            matrix[7] = 0.475f;
            matrix[8] = 0.525f;
            break;

        default:
            break;
    }

    m_shader.setUniformArray("matrix", matrix, 9);
    m_shader.setUniform("texture", sf::Shader::CurrentTexture);
}

}
