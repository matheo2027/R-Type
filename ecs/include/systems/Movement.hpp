/**
 * @file Movement.hpp
 * @brief Movement system for managing entity movements.
 *
 * This file contains the declaration of the Movement class, which is
 * responsible for updating the position of entities based on their
 * velocity in the game.
 */

#pragma once

#include <vector>

#include "systems/ISystem.hpp"
#include "EntityManager.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"

namespace systems
{

/**
 * @class Movement
 * @brief A system for updating entity movements based on velocity.
 *
 * The Movement class implements the ISystem interface and is used to
 * manage and update the movement of entities in the game. It modifies
 * the position of entities based on their velocity each frame.
 */
class Movement : public ISystem
{
    public:
        /**
         * @brief Constructs a Movement system.
         * @param entityManager Reference to the EntityManager for managing entities.
         */
        Movement(ecs::EntityManager &entityManager);

        /**
         * @brief Updates the positions of entities based on their velocity.
         * @param dt The time elapsed since the last update, in seconds.
         */
        void update(float dt);

    private:
        ecs::EntityManager &m_entityManager; ///< Reference to the EntityManager.
};

} // namespace systems
