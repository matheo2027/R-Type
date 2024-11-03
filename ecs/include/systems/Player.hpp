#pragma once

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"
#include "systems/ISystem.hpp"
#include "components/Velocity.hpp"

namespace systems
{

class Server;

/**
 * @class Player
 * @brief A system responsible for handling player actions and interactions within the game.
 *
 * This class implements the ISystem interface and manages player input, movement,
 * and shooting mechanics by interacting with the EntityManager and display system.
 */
class Player : public ISystem
{
    public:
        /**
         * @brief Constructs a Player system.
         *
         * @param entityManager Reference to the EntityManager to manage game entities.
         * @param display Reference to the display system for rendering.
         */
        Player(ecs::EntityManager &entityManager, systems::Server &server); 

        /**
         * @brief Updates the player system for the current frame.
         *
         * This function is called once per frame and handles all player-related updates,
         * including input processing and movement.
         *
         * @param dt Time elapsed since the last update in seconds.
         */
        void update(float dt) override;

    private:
        ecs::EntityManager &m_entityManager; ///< Reference to the EntityManager for managing entities.
        systems::Server &m_server; ///< Reference to the Server system for handling game logic.

        /**
         * @brief Handles player movement.
         *
         * This function updates the player's position based on the current velocity.
         *
         * @param player Pointer to the Player component.
         * @param velocity Pointer to the Velocity component affecting the player's movement.
         */
        void playerMovement(component::Player *player, component::Velocity *velocity);

        /**
         * @brief Handles player shooting mechanics.
         *
         * This function processes shooting actions and updates the player's position accordingly.
         *
         * @param dt Time elapsed since the last update in seconds.
         * @param player Pointer to the Player component.
         * @param position Pointer to the Position component of the player.
         */
        void playerShoot(float dt, component::Player *player, component::Position *position);
};

}
