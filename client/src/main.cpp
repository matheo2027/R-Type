#include "DisplaySFML.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    std::string title = "SFML Window";
    gfx::DisplaySFML display(800, 600, title);

    while (display.isRunning())
    {
        sf::Event event;
        while (display.isRunning() && display.m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                display.close();
            }
        }

        display.clear();
        display.draw("Hello, SFML!", 200, 150);

        if (display.getKeyDown(gfx::K_ESC))
        {
            display.close();
        }

        display.update();
    }

    return 0;
}
