#include "systems/Render.hpp"
#include <iostream>

namespace systems
{

Render::Render(ecs::EntityManager &entityManager, display::IDisplay &display)
    : m_entityManager(entityManager), m_display(display)
{
}

void Render::update(float dt)
{
    (void)dt;

    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto position = m_entityManager.getComponent<component::Position>(i);
        auto texture = m_entityManager.getComponent<component::Texture>(i);

        if (position && texture) {
            m_display.draw(texture->texture, position->x, position->y);
        }
    }
}

}