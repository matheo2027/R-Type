#include "systems/Movement.hpp"
#include <cmath>

namespace systems {

Movement::Movement(ecs::EntityManager &entityManager, systems::Server &server)
    : m_entityManager(entityManager), m_server(server)
{
}

void Movement::update(float dt)
{
    // Vérifier si le joueur est mort
    bool playerDead = false;
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto player = m_entityManager.getComponent<component::Player>(i);
        auto health = m_entityManager.getComponent<component::Health>(i);
        if (player && health && health->currentHealth <= 0) {
            playerDead = true;
            break;
        }
    }

    // Si le joueur est mort, ne pas mettre à jour les mouvements
    if (playerDead) {
        return;
    }

    // Sinon, mettre à jour les mouvements normalement
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto position = m_entityManager.getComponent<component::Position>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);
        auto pattern = m_entityManager.getComponent<component::Pattern>(i);

        if (position && velocity) {
            if (pattern) {
                pattern->elapsedTime += dt;
                velocity->vx = pattern->directionX * pattern->speed;
                velocity->vy = pattern->directionY * pattern->speed + pattern->amplitude * std::sin(pattern->frequency * pattern->elapsedTime);
            }
            position->x += velocity->vx * dt;
            position->y += velocity->vy * dt;
        }
    }
}

}