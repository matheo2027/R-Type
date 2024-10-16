#pragma once

#include <vector>
#include <memory>

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"
#include "systems/ISystem.hpp"

namespace systems
{

class Render : public ISystem
{
    public:
        Render(ecs::EntityManager &entityManager, display::IDisplay &display);

        void update(float dt);

    private:
        ecs::EntityManager &m_entityManager;
        display::IDisplay &m_display;
};

}
