#pragma once

#include <vector>

#include "systems/ISystem.hpp"
#include "EntityManager.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"

namespace systems
{

class Movement : public ISystem
{
    public:
        Movement(ecs::EntityManager &entityManager);

        void update(float dt);

    private:
        ecs::EntityManager &m_entityManager;
};

}