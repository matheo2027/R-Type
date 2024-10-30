/**
 * @file Render.hpp
 * @brief Declaration of the Render class for rendering entities in the ECS.
 *
 * This class is responsible for rendering entities to the display using
 * an entity-manager system. It implements the ISystem interface.
 */

#pragma once

#include <vector>
#include <memory>

#include "EntityManager.hpp"
#include "display/IDisplay.hpp"
#include "systems/ISystem.hpp"

namespace systems
{

/**
 * @class Render
 * @brief Handles the rendering of entities in the game.
 *
 * The Render class is part of the ECS (Entity-Component-System) architecture.
 * It is responsible for updating and rendering entities to the display each frame.
 */
class Render : public ISystem
{
    public:
        /**
         * @brief Constructs a Render object.
         * @param entityManager Reference to the EntityManager that manages the entities.
         * @param display Reference to the display interface used for rendering.
         */
        Render(ecs::EntityManager &entityManager, display::IDisplay &display);

        /**
         * @brief Updates the rendering system.
         *
         * This method is called every frame to update the rendering of entities.
         * @param dt The time elapsed since the last update, in seconds.
         */
        void update(float dt);

    private:
        ecs::EntityManager &m_entityManager; ///< Reference to the EntityManager.
        display::IDisplay &m_display;         ///< Reference to the display interface.
};

}
