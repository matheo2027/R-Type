/**
 * @file SystemManager.cpp
 * @brief Implementation of the SystemManager class for managing ECS systems.
 *
 * This file contains the definition of the SystemManager class, which is responsible
 * for updating all systems in the Entity-Component-System (ECS) architecture.
 */

#include "SystemManager.hpp"

namespace ecs
{

/**
 * @brief Constructs a SystemManager instance.
 *
 * This constructor initializes the SystemManager, preparing it to manage systems.
 */
SystemManager::SystemManager()
{
}

/**
 * @brief Updates all registered systems.
 *
 * This method iterates through all systems and calls their update function.
 *
 * @param dt The time step for the update, typically the frame time.
 */
void SystemManager::update(float dt)
{
    for (auto &system : systems) {
        system->update(dt);
    }
}

}
