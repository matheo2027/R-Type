#pragma once

#include "EntityManager.hpp"
#include "systems/ISystem.hpp"

namespace systems
{

/**
 * @class Box
 * @brief This class represents a system that manages box-related entities.
 *
 * The Box class is derived from the ISystem interface and is responsible for
 * updating box entities within the ECS (Entity-Component-System) architecture.
 */
class Box : public ISystem
{
public:
    /**
     * @brief Constructs a Box system.
     *
     * @param entityManager Reference to the EntityManager for managing entities.
     */
    Box(ecs::EntityManager &entityManager);

    /**
     * @brief Updates the Box system.
     *
     * This method is called to update the state of the box entities.
     *
     * @param dt The time elapsed since the last update (in seconds).
     */
    void update(float dt) override;

private:
    ecs::EntityManager &m_entityManager; ///< Reference to the EntityManager instance.
};

} // namespace systems
