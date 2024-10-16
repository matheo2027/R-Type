#include "systems/Player.hpp"
#include <iostream>

namespace systems
{

Player::Player(ecs::EntityManager &entityManager, display::IDisplay &display)
    : m_entityManager(entityManager), m_display(display)
{
}

void Player::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto player = m_entityManager.getComponent<component::Player>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);

        if (player) {
            playerInput(player);
            playerMovement(player, velocity);
            playerShoot(dt, player, position);
        }
    }
}

void Player::playerInput(component::Player *player)
{
    player->up = m_display.isKeyPressed(display::Key::K_UP);
    player->down = m_display.isKeyPressed(display::Key::K_DOWN);
    player->left = m_display.isKeyPressed(display::Key::K_LEFT);
    player->right = m_display.isKeyPressed(display::Key::K_RIGHT);
    player->shoot = m_display.isKeyPressed(display::Key::K_SPACE);
}

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

void Player::playerShoot(float dt, component::Player *player, component::Position *position)
{
    if (player->shoot && player->shootingCooldown <= 0) {
        ecs::Entity bullet = m_entityManager.createEntity();
        m_entityManager.addComponent<component::Position>(bullet, position->x, position->y);
        m_entityManager.addComponent<component::Bullet>(bullet, 200.0f, 0.0f);
        m_entityManager.addComponent<component::Velocity>(bullet, 0, 0);
        m_entityManager.addComponent<component::Box>(bullet, position->x + 100, position->y, 10, 10);

        std::shared_ptr<display::ITexture> texture = m_display.createTexture("../assets/img/player_bullet.png");
        m_entityManager.addComponent<component::Texture>(bullet, texture);

        player->shootingCooldown = player->shootingSpeed;
    }

    player->shootingCooldown -= dt;
}

}
