#define _USE_MATH_DEFINES
#include <cmath>
#include "systems/Enemie.hpp"

namespace systems {

Enemie::Enemie(ecs::EntityManager &entityManager, systems::Server &server)
    : m_entityManager(entityManager), m_server(server)
{
}

void Enemie::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto enemie = m_entityManager.getComponent<component::Enemie>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);
        auto pattern = m_entityManager.getComponent<component::Pattern>(i);

        if (enemie && pattern) {
            enemieMovement(enemie, velocity);
            enemieShoot(dt, enemie, position);
        }
    }
}

void Enemie::enemieMovement(component::Enemie *enemie, component::Velocity *velocity)
{
    if (velocity) {
        velocity->vx = -200.0f;  // Déplacement vers la gauche
        velocity->vy = 0.0f;
    }
}

void Enemie::enemieShoot(float dt, component::Enemie *enemie, component::Position *position)
{
    enemie->shootingCooldown += dt;
    
    if (enemie->shootingCooldown >= enemie->shootingSpeed) {
        enemie->shootingCooldown = 0.0f;
        
        ecs::Entity bullet = m_entityManager.createEntity();
        m_entityManager.addComponent<component::Position>(bullet, position->x - 20, position->y);
        m_entityManager.addComponent<component::Velocity>(bullet, -200.0f, 0.0f);
        m_entityManager.addComponent<component::Bullet>(bullet, 200.0f, M_PI);
        m_entityManager.addComponent<component::Box>(bullet, position->x, position->y, 10, 10);
        m_entityManager.addComponent<component::Owner>(bullet, component::Owner::Type::Enemie);
        
        std::cout << "Bullet created by Enemie ID " << enemie << " at position (" << position->x << ", " << position->y << ")" << std::endl;
        
        // Utiliser spawnEntity du Server pour créer la texture
        m_server.spawnEntity(bullet, position->x - 20, position->y, "assets/img/enemie_bullet.png");
    }
}

}