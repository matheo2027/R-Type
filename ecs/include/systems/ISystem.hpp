#pragma once

namespace systems
{

/**
 * @brief Abstract base class for systems in the ECS (Entity-Component-System) architecture.
 *
 * This class serves as an interface for all systems, providing a common method for updating
 * their state based on the elapsed time.
 */
class ISystem
{
    public:
        /// Virtual destructor for proper cleanup of derived classes.
        virtual ~ISystem() = default;

        /**
         * @brief Updates the system's state.
         *
         * This method should be implemented by derived classes to perform necessary updates
         * during each frame of the game loop.
         *
         * @param dt The time elapsed since the last update in seconds.
         */
        virtual void update(float dt) = 0;
};

} // namespace systems
