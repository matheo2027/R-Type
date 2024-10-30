/**
 * @file Health.hpp
 * @brief Header file for the Health component.
 *
 * This file defines the Health component used in the ECS (Entity-Component-System)
 * architecture for managing the health status of entities in the game.
 */

#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "Component.hpp"

namespace component
{

/**
 * @struct Health
 * @brief Represents the health status of an entity.
 *
 * The Health struct holds the maximum and current health values for an entity.
 * It is derived from the Component class, enabling it to be used within an
 * ECS framework.
 */
struct Health : public Component {
    /// The maximum health value of the entity.
    int max;

    /// The current health value of the entity.
    int current;

    /**
     * @brief Constructs a Health component with specified maximum and current values.
     *
     * @param max The maximum health value.
     * @param current The current health value.
     */
    Health(int max, int current) : max(max), current(current) {}
};

} // namespace component

#endif // HEALTH_HPP
