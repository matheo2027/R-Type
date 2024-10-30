/**
 * @file Component.hpp
 * @brief Header file for the Component structure.
 *
 * This file defines the base class for all components in the ECS (Entity-Component-System) architecture.
 */

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace component
{

/**
 * @struct Component
 * @brief Base class for all components in the ECS.
 *
 * The Component struct serves as a base class for all components used in the ECS architecture.
 * It provides a virtual destructor to ensure proper cleanup of derived classes.
 * All components should inherit from this struct to be managed by the ECS.
 */
struct Component
{
    /**
     * @brief Virtual destructor for the Component struct.
     *
     * The virtual destructor allows for proper cleanup of derived classes.
     */
    virtual ~Component() = default;
};

}

#endif // COMPONENT_HPP
