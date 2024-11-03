#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"
#include "components/Owner.hpp"

#include <cmath>

namespace systems
{

/**
 * @class Bullet
 * @brief Manages bullet behavior in the game.
 *
 * The Bullet class is responsible for updating bullet movements and handling collisions
 * with other entities in the game. It implements the ISystem interface to integrate
 * with the entity-component-system architecture.
 */
class Bullet : public ISystem
{
    public:
        /**
         * @brief Constructs a Bullet system.
         * @param entityManager Reference to the EntityManager to manage entities.
         */
        Bullet(ecs::EntityManager &entityManager);

        /**
         * @brief Updates the bullet system.
         * @param dt The time delta since the last update, used for frame-independent movement.
         *
         * This method is called each frame to update the state of bullets,
         * including their movements and handling collisions.
         */
        void update(float dt) override;

    private:
        ecs::EntityManager &m_entityManager; ///< Reference to the EntityManager for managing bullets.

        /**
         * @brief Handles bullet movement.
         * @param bullet Pointer to the Bullet component to move.
         * @param velocity Pointer to the Velocity component associated with the bullet.
         *
         * This method updates the position of the bullet based on its velocity.
         */
        void bulletMovement(component::Bullet *bullet, component::Velocity *velocity);

        /**
         * @brief Handles bullet collisions.
         * @param bullet Pointer to the Bullet component involved in the collision.
         * @param position Pointer to the Position component of the bullet.
         * @param box Pointer to the Box component for collision detection.
         * @param id The identifier of the entity the bullet is colliding with.
         *
         * This method checks for collisions and handles the necessary responses
         * when a bullet collides with other entities.
         */
        void bulletCollision(component::Bullet *bullet, component::Position *position, component::Box *box, unsigned int id);
};

}
