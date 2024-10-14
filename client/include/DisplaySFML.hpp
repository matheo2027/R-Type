#pragma once
#include "IDisplay.hpp"
#include <SFML/Graphics.hpp>

namespace gfx
{
    class DisplaySFML : public IDisplay
    {
    public:
        DisplaySFML(u32 width, u32 height, std::string &title);

        void update() override;
        void clear() override;
        bool isRunning() const override;
        void close() override;
        void draw(const ITexture &texture, u32 x, u32 y) override;
        void draw(const std::string &text, u32 x, u32 y) override;
        bool getKeyDown(u8 key) const override;
        sf::RenderWindow m_window;
    };
}
