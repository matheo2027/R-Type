#include "systems/Bullet.hpp"

namespace systems
{

/**
 * @class Bullet
 * @brief A system for managing bullet behavior in the game.
 *
 * This class is responsible for updating the bullets' positions and handling collisions
 * with enemy entities.
 */
Bullet::Bullet(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

/**
 * @brief Updates the bullet system.
 *
 * This method iterates over all entities managed by the entity manager and updates the
 * bullets' movement and collision states.
 *
 * @param dt The delta time since the last update, used for timing purposes.
 */
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

/**
 * @brief Calculates the movement of a bullet.
 *
 * This method sets the velocity of the bullet based on its speed and angle.
 *
 * @param bullet A pointer to the Bullet component.
 * @param velocity A pointer to the Velocity component that will be updated.
 */
void Bullet::bulletMovement(component::Bullet *bullet, component::Velocity *velocity)
{
    if (velocity) {
        velocity->vy = (bullet->speed * sin(bullet->angle));
        velocity->vx = (bullet->speed * cos(bullet->angle));
    }
}

/**
 * @brief Handles collision detection for bullets.
 *
 * This method checks for collisions between bullets and enemies. If a collision is detected,
 * both the bullet and the enemy entities are removed from the entity manager.
 *
 * @param bullet A pointer to the Bullet component.
 * @param position A pointer to the Position component of the bullet.
 * @param box A pointer to the Box component of the bullet.
 * @param id The ID of the bullet entity.
 */
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
