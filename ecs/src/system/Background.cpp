#include "systems/Background.hpp"
#include "components/Background.hpp"

namespace systems
{

Background::Background(ecs::EntityManager &entityManager, display::IDisplay &display)
    : m_entityManager(entityManager), m_display(display)
{
}

void Background::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto background = m_entityManager.getComponent<component::Background>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);
    }
}

}
