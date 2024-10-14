#include "DisplaySFML.hpp"
#include <iostream>

namespace gfx
{
    DisplaySFML::DisplaySFML(u32 width, u32 height, std::string &title)
        : IDisplay(width, height, title), m_window(sf::VideoMode(width, height), title)
    {
    }

    void DisplaySFML::update()
    {
        m_window.display();
    }

    void DisplaySFML::clear()
    {
        m_window.clear();
    }

    bool DisplaySFML::isRunning() const
    {
        return m_window.isOpen();
    }

    void DisplaySFML::close()
    {
        m_window.close();
    }

    void DisplaySFML::draw(const ITexture &texture, u32 x, u32 y)
    {
        sf::Texture sfTexture;
        if (!sfTexture.loadFromFile(texture.getPath().string()))
            return;

        sf::Sprite sprite(sfTexture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        m_window.draw(sprite);
    }

    void DisplaySFML::draw(const std::string &text, u32 x, u32 y)
    {
        sf::Font font;
        if (!font.loadFromFile("assets/ArialMT.ttf"))
            return;

        sf::Text sfText;
        sfText.setFont(font);
        sfText.setString(text);
        sfText.setPosition(static_cast<float>(x), static_cast<float>(y));
        sfText.setCharacterSize(24);
        sfText.setFillColor(sf::Color::White);

        m_window.draw(sfText);
    }

    bool DisplaySFML::getKeyDown(u8 key) const
    {
        switch (key)
        {
            case K_UP: return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            case K_DOWN: return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            case K_LEFT: return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            case K_RIGHT: return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            case K_SPACE: return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
            case K_ESC: return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
            default: return false;
        }
    }
}
