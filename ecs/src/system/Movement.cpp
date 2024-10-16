#include "systems/Movement.hpp"
#include <iostream>

namespace systems
{

Movement::Movement(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

void Movement::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto position = m_entityManager.getComponent<component::Position>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);

        if (position && velocity) {
            position->x += velocity->vx * dt;
            position->y += velocity->vy * dt;
        }
    }
}
    
}