/**
 * @file Enemie.hpp
 * @brief This file contains the declaration of the Enemie class,
 *        which is responsible for managing enemy behavior in the game.
 */

#pragma once

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"
#include "systems/ISystem.hpp"

#include <cmath>

namespace systems
{

/**
 * @class Enemie
 * @brief The Enemie class implements the ISystem interface to manage enemy behavior in the game.
 *
 * This class handles enemy movement and shooting mechanics,
 * updating the state of enemies based on the elapsed time.
 */
class Enemie : public ISystem
{
    public:
        /**
         * @brief Constructs an Enemie instance.
         *
         * @param entityManager A reference to the EntityManager managing game entities.
         */
        Enemie(ecs::EntityManager &entityManager);

        /**
         * @brief Updates enemy behavior based on the elapsed time.
         *
         * This method is called every frame to update the position and actions
         * of the enemies in the game.
         *
         * @param dt The elapsed time since the last update in seconds.
         */
        void update(float dt) override;

    private:
        ecs::EntityManager &m_entityManager; ///< Reference to the EntityManager.

        /**
         * @brief Handles enemy movement.
         *
         * This method updates the position of a given enemy based on its velocity.
         *
         * @param enemie A pointer to the Enemie component of the enemy.
         * @param velocity A pointer to the Velocity component of the enemy.
         */
        void enemieMovement(component::Enemie *enemie, component::Velocity *velocity);

        /**
         * @brief Handles enemy shooting behavior.
         *
         * This method determines if the enemy should shoot and updates its state accordingly.
         *
         * @param dt The elapsed time since the last update in seconds.
         * @param enemie A pointer to the Enemie component of the enemy.
         * @param position A pointer to the Position component of the enemy.
         */
        void enemieShoot(float dt, component::Enemie *enemie, component::Position *position);
};

}
