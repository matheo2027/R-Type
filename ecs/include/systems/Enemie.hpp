#pragma once

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"
#include "systems/ISystem.hpp"

#include <cmath>

namespace systems
{

class Enemie : public ISystem
{
    public:
        Enemie(ecs::EntityManager &entityManager);

        void update(float dt) override;

    private:
        ecs::EntityManager &m_entityManager;

        void enemieMovement(component::Enemie *enemie, component::Velocity *velocity);
        void enemieShoot(float dt, component::Enemie *enemie, component::Position *position);

};

}