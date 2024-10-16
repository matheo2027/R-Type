#include "systems/Box.hpp"

namespace systems
{

Box::Box(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

void Box::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto box = m_entityManager.getComponent<component::Box>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);

        if (box && position) {
            box->x = position->x;
            box->y = position->y;
        }
    }
}

}