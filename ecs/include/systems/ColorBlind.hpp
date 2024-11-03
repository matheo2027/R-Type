#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"
#include "display/IDisplay.hpp"

namespace systems
{

class ColorBlind : public ISystem
{
    public:
        ColorBlind(ecs::EntityManager &entityManager, display::IDisplay &display);
        void update(float dt);

    private:
        ecs::EntityManager &m_entityManager;
        display::IDisplay &m_display;

        int m_colorBlind = 0;
        int m_maxColorBlind = 3;

        float m_countdown = 0.0f;
};

} // namespace systems