#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"

#include <cmath>

namespace systems
{

class Bullet : public ISystem
{
    public:
        Bullet(ecs::EntityManager &entityManager);

        void update(float dt) override;

    private:
        ecs::EntityManager &m_entityManager;

        void bulletMovement(component::Bullet *bullet, component::Velocity *velocity);
        void bulletCollision(component::Bullet *bullet, component::Position *position, component::Box *box, unsigned int id);
};

}
