#pragma once

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"

namespace systems
{

class Background
{

public:
    Background(ecs::EntityManager &entityManager, display::IDisplay &display);
    void update(float dt);

private:
    ecs::EntityManager &m_entityManager;
    display::IDisplay &m_display;

};

}