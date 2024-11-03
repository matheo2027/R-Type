/**
 * @file SystemManager.hpp
 * @brief Manages all systems in the ECS (Entity-Component-System) architecture.
 *
 * This file defines the SystemManager class, which is responsible for updating
 * and managing different systems used in the game. It holds a collection of systems
 * that implement the ISystem interface.
 *
 * @note Systems are used to handle specific game functionalities such as movement,
 * rendering, player interactions, enemy behavior, bullet management, and box handling.
 */

#pragma once

#include "systems/Movement.hpp"
#include "systems/Render.hpp"
#include "systems/Player.hpp"
#include "systems/Enemie.hpp"
#include "systems/Bullet.hpp"
#include "systems/Box.hpp"
#include "systems/Server.hpp"
#include "systems/Client.hpp"
#include "systems/Background.hpp"
#include <vector>

namespace ecs
{
    /**
     * @class SystemManager
     * @brief Class responsible for managing and updating game systems.
     *
     * The SystemManager class maintains a collection of systems and updates them
     * during each frame of the game. It allows for adding new systems dynamically
     * at runtime.
     */
    class SystemManager
    {
    public:
        /**
         * @brief Constructs a new SystemManager object.
         *
         * Initializes the SystemManager and prepares it to manage game systems.
         */
        SystemManager();

        /**
         * @brief Updates all managed systems.
         *
         * This method is called each frame to update all systems with the
         * elapsed time since the last frame.
         *
         * @param dt The elapsed time since the last frame, in seconds.
         */
        void update(float dt);

        /**
         * @brief Adds a new system to the manager.
         *
         * This method allows for the addition of a new system of type T,
         * which must inherit from systems::ISystem. The system is constructed
         * with the provided arguments.
         *
         * @tparam T The type of system to add.
         * @tparam Args Variadic template for constructor arguments of the system.
         * @param args The constructor arguments for the new system.
         */
        template <typename T, typename... Args>
        void addSystem(Args &&...args)
        {
            systems.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        }

        template <typename T>
        T &getSystem()
        {
            for (auto &system : systems)
            {
                if (dynamic_cast<T *>(system.get()))
                {
                    return *dynamic_cast<T *>(system.get());
                }
            }

            throw std::runtime_error("System not found.");
        }

    private:
        /**
         * @brief Vector of unique pointers to the systems managed by this class.
         *
         * This vector stores all systems that the SystemManager is responsible for.
         */
        std::vector<std::unique_ptr<systems::ISystem>> systems;
    };
}
