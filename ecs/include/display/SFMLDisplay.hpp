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

struct SFMLTexture : public ITexture
{
    SFMLTexture(const std::string &path) : ITexture(path)
    {
        texture.loadFromFile(path);
        sprite.setTexture(texture);
    }

    ~SFMLTexture() override = default;

    sf::Texture texture;
    sf::Sprite sprite;
};

class SFMLDisplay : public IDisplay
{
    public:
        SFMLDisplay();
        ~SFMLDisplay() override;

        void init(int width, int height, const std::string &title) override;

        void update() override;
        void clear() override;

        bool isOpen() const override;
        void close() override;

        void draw(std::shared_ptr<ITexture> &texture, float x, float y) override;

        bool isKeyPressed(Key key) const override;
        bool isKeyReleased(Key key) const override;

        std::shared_ptr<ITexture> createTexture(const std::string &path);

    private:
        std::vector<sf::Keyboard::Key> m_keys;
        sf::RenderWindow *m_window;
};

}