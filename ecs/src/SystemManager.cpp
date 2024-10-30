/**
 * @file SystemManager.hpp
 * @brief This file defines the SystemManager class for managing ECS (Entity-Component-System) systems.
 */

#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include <vector>
#include <memory>
#include "System.hpp"

namespace ecs
{

/**
 * @class SystemManager
 * @brief Manages a collection of systems in the ECS architecture.
 *
 * The SystemManager is responsible for updating all systems in the ECS framework
 * at each frame. It iterates through the list of systems and calls their update
 * methods with the time delta.
 */
class SystemManager
{
public:
    /**
     * @brief Constructs a new SystemManager object.
     *
     * Initializes an empty SystemManager.
     */
    SystemManager();

    /**
     * @brief Updates all registered systems.
     *
     * Calls the update method on each system in the systems vector.
     *
     * @param dt The time delta since the last update, used to synchronize system updates.
     */
    void update(float dt);

private:
    /// A vector of unique pointers to the systems managed by this SystemManager.
    std::vector<std::unique_ptr<System>> systems;
};

} // namespace ecs

#endif // SYSTEMMANAGER_HPP
