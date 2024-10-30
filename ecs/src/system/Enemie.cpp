/**
 * @file Enemie.hpp
 * @brief Contains the definition of the Enemie class responsible for enemy behavior in the game.
 *
 * This file includes the implementation of enemy movement and shooting mechanisms within the game
 * using an Entity-Component-System (ECS) architecture.
 */

#include "systems/Enemie.hpp"

namespace systems
{

/**
 * @brief Constructs an Enemie instance.
 *
 * Initializes the Enemie system with the provided entity manager.
 *
 * @param entityManager Reference to the entity manager that manages game entities.
 */
Enemie::Enemie(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

/**
 * @brief Updates the enemy states.
 *
 * This method iterates through all entities managed by the entity manager. For each entity,
 * it checks if it has the necessary components to perform enemy movement and shooting.
 *
 * @param dt The time elapsed since the last update (in seconds).
 */
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

/**
 * @brief Handles the movement of an enemy.
 *
 * Updates the velocity of the enemy based on its speed.
 *
 * @param enemie Pointer to the enemy component.
 * @param velocity Pointer to the velocity component of the enemy.
 */
void Enemie::enemieMovement(component::Enemie *enemie, component::Velocity *velocity)
{
    if (velocity) {
        velocity->vx = 0;
        velocity->vy = sin(velocity->vx) * enemie->speed;
    }
}

/**
 * @brief Handles the shooting behavior of an enemy.
 *
 * This function currently contains commented-out logic for shooting bullets.
 * It increments the shooting cooldown and checks if the enemy is ready to shoot.
 * When ready, it creates a new bullet entity and initializes its components.
 *
 * @param dt The time elapsed since the last update (in seconds).
 * @param enemie Pointer to the enemy component.
 * @param position Pointer to the position component of the enemy.
 */
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
