/**
 * @file Player.hpp
 * @brief Contains the Player class that manages player input, movement, and shooting mechanics in the game.
 *
 * This file defines the Player class, which interacts with the EntityManager and display systems
 * to handle player actions such as moving and shooting. The Player class processes input and updates
 * the player's position and velocity based on user commands.
 *
 * @namespace systems
 *
 * @see ecs::EntityManager
 * @see display::IDisplay
 * @see component::Player
 * @see component::Velocity
 * @see component::Position
 */

#include "systems/Player.hpp"
#include "systems/Server.hpp"
#include <iostream>

namespace systems
{

/**
 * @brief Constructs a Player object.
 *
 * @param entityManager Reference to the EntityManager used to manage entities and their components.
 * @param display Reference to the display interface used for input handling.
 */
Player::Player(ecs::EntityManager &entityManager, systems::Server &server)
    : m_entityManager(entityManager), m_server(server)
{
}

/**
 * @brief Updates the player's state based on input and movement.
 *
 * This method iterates through all entities managed by the EntityManager,
 * checks for player components, and processes input for movement and shooting.
 *
 * @param dt Delta time since the last update.
 */
void Player::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto player = m_entityManager.getComponent<component::Player>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);

        if (player) {
            playerMovement(player, velocity);
            playerShoot(dt, player, position);
        }
    }
}

/**
 * @brief Processes player input to update movement state.
 *
 * This method checks the current state of input keys and updates the player's
 * movement direction accordingly.
 *
 * @param player Pointer to the Player component to update.
 */

/**
 * @brief Updates the player's velocity based on movement input.
 *
 * This method calculates the new velocity for the player based on the
 * current input direction. It sets the velocity components to zero and
 * updates them based on the player's input state.
 *
 * @param player Pointer to the Player component.
 * @param velocity Pointer to the Velocity component to be updated.
 */
void Player::playerMovement(component::Player *player, component::Velocity *velocity)
{
    if (velocity) {
        velocity->vx = 0;
        velocity->vy = 0;

        if (player->up) {
            velocity->vy = -player->speed;
        }

        if (player->down) {
            velocity->vy = player->speed;
        }

        if (player->left) {
            velocity->vx = -player->speed;
        }

        if (player->right) {
            velocity->vx = player->speed;
        }
    }
}

/**
 * @brief Handles shooting logic for the player.
 *
 * This method checks if the player is attempting to shoot and if the shooting
 * cooldown period has elapsed. If so, it creates a new bullet entity,
 * initializes its components, and sets the shooting cooldown.
 *
 * @param dt Delta time since the last update.
 * @param player Pointer to the Player component.
 * @param position Pointer to the Position component to get the player's current position.
 */
void Player::playerShoot(float dt, component::Player *player, component::Position *position)
{
    if (player->shoot && player->shootingCooldown <= 0) {
        ecs::Entity bullet = m_entityManager.createEntity();
        m_entityManager.addComponent<component::Position>(bullet, position->x, position->y);
        m_entityManager.addComponent<component::Bullet>(bullet, 200.0f, 0.0f);
        m_entityManager.addComponent<component::Velocity>(bullet, 0, 0);
        m_entityManager.addComponent<component::Box>(bullet, position->x + 100, position->y, 10, 10);

        m_server.spawnEntity(bullet, position->x, position->y, "assets/img/player_bullet.png");

        player->shootingCooldown = player->shootingSpeed;
    }

    player->shootingCooldown -= dt;
}

}
