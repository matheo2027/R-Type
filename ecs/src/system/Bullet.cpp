#include "systems/Bullet.hpp"

namespace systems
{

Bullet::Bullet(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

void Bullet::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto bullet = m_entityManager.getComponent<component::Bullet>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);
        auto box = m_entityManager.getComponent<component::Box>(i);

        if (bullet && velocity && position) {
            bulletMovement(bullet, velocity);
        }

        if (bullet && position && box) {
            bulletCollision(bullet, position, box, i);
        }
    }
}

void Bullet::bulletMovement(component::Bullet *bullet, component::Velocity *velocity)
{
    if (velocity) {
        velocity->vy = (bullet->speed * sin(bullet->angle));
        velocity->vx = (bullet->speed * cos(bullet->angle));
    }
}

void Bullet::bulletCollision(component::Bullet *bullet, component::Position *position, component::Box *box, unsigned int id)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto enemie = m_entityManager.getComponent<component::Enemie>(i);
        auto enemieBox = m_entityManager.getComponent<component::Box>(i);

        if (enemie && enemieBox) {
            if (box->testCollision(*enemieBox)) {
                m_entityManager.removeEntity(id);
                m_entityManager.removeEntity(i);
            }
        }
    }

}

}