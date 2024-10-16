#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"

namespace systems
{

class Box : public ISystem
{
    public:
        Box(ecs::EntityManager &entityManager);

        void update(float dt) override;

    private:
        ecs::EntityManager &m_entityManager;
};

}