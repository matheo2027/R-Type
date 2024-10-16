#include "systems/Enemie.hpp"

namespace systems
{

Enemie::Enemie(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

void Enemie::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto enemie = m_entityManager.getComponent<component::Enemie>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);

        if (enemie) {
            enemieMovement(enemie, velocity);
            enemieShoot(dt, enemie, position);
        }
    }
}

void Enemie::enemieMovement(component::Enemie *enemie, component::Velocity *velocity)
{
    if (velocity) {
        velocity->vx = 0;
        velocity->vy = sin(velocity->vx) * enemie->speed;
    }
}

void Enemie::enemieShoot(float dt, component::Enemie *enemie, component::Position *position)
{
    // enemie->shootingCooldown += dt;

    // if (enemie->shootingCooldown >= enemie->shootingSpeed) {
    //     enemie->shootingCooldown = 0.0f;

    //     ecs::Entity bullet = m_entityManager.createEntity();
    //     m_entityManager.addComponent<component::Position>(bullet, position->x, position->y);
    //     m_entityManager.addComponent<component::Velocity>(bullet, 0, 100);
    //     m_entityManager.addComponent<component::Bullet>(bullet, 100, 0);
    // }

}

}

