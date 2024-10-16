#pragma once

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"
#include "systems/ISystem.hpp"
#include "components/Velocity.hpp"
#include "components/Player.hpp"

namespace systems
{

class Player : public ISystem
{
    public:
        Player(ecs::EntityManager &entityManager, display::IDisplay &display);

        void update(float dt) override;

    private:
        ecs::EntityManager &m_entityManager;
        display::IDisplay &m_display;

        void playerInput(component::Player *player);
        void playerMovement(component::Player *player, component::Velocity *velocity);
        void playerShoot(float dt, component::Player *player, component::Position *position);

};

}