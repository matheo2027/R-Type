#include "display/SFMLDisplay.hpp"
#include <iostream>

namespace display
{

SFMLDisplay::SFMLDisplay()
{
    m_keys.push_back(sf::Keyboard::Key::Up);
    m_keys.push_back(sf::Keyboard::Key::Down);
    m_keys.push_back(sf::Keyboard::Key::Left);
    m_keys.push_back(sf::Keyboard::Key::Right);
    m_keys.push_back(sf::Keyboard::Key::Space);
}

SFMLDisplay::~SFMLDisplay()
{
    delete m_window;
}

void SFMLDisplay::init(int width, int height, const std::string &title)
{
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

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

void SFMLDisplay::clear()
{
    m_window->clear();
}

bool SFMLDisplay::isOpen() const
{
    return m_window->isOpen();
}

void SFMLDisplay::close()
{
    m_window->close();
}

void SFMLDisplay::draw(std::shared_ptr<ITexture> &texture, float x, float y)
{
    auto &sfmlTexture = static_cast<SFMLTexture &>(*texture);

    sfmlTexture.sprite.setPosition(x, y);

    m_window->draw(sfmlTexture.sprite);
}

bool SFMLDisplay::isKeyPressed(Key key) const
{
    return sf::Keyboard::isKeyPressed(m_keys[key]);
}

bool SFMLDisplay::isKeyReleased(Key key) const
{
    return !sf::Keyboard::isKeyPressed(m_keys[key]);
}

std::shared_ptr<ITexture> SFMLDisplay::createTexture(const std::string &path)
{
    return std::make_shared<SFMLTexture>(path);
}

}