#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"
#include "systems/Server.hpp"
#include "components/Enemie.hpp"
#include "components/Velocity.hpp"
#include "components/Position.hpp"
#include "components/Pattern.hpp"
#include "components/Bullet.hpp"
#include "components/Box.hpp"
#include "components/Texture.hpp"
#include "components/Owner.hpp"

#include <cmath>

namespace systems {

class Enemie : public ISystem {
public:
    Enemie(ecs::EntityManager &entityManager, systems::Server &server);
    void update(float dt) override;

private:
    ecs::EntityManager &m_entityManager;
    systems::Server &m_server;
    void enemieMovement(component::Enemie *enemie, component::Velocity *velocity);
    void enemieShoot(float dt, component::Enemie *enemie, component::Position *position);
};

}