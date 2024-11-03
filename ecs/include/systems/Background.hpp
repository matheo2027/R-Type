#pragma once

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"
#include "components/Background.hpp"
#include "systems/ISystem.hpp"

namespace systems {

class Background : public ISystem {
public:
    Background(ecs::EntityManager &entityManager, display::IDisplay &display);
    void update(float dt) override;

private:
    ecs::EntityManager &m_entityManager;
    display::IDisplay &m_display;
};

} // namespace systems