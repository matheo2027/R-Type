/**
 * @file Box.hpp
 * @brief Implementation of the Box system in the ECS.
 *
 * This file contains the implementation of the Box system which updates the
 * position of boxes in the entity-component-system (ECS) based on their
 * associated position components.
 */

#include "systems/Box.hpp"

namespace systems
{

/**
 * @brief Constructs a Box system.
 *
 * Initializes the Box system with the provided entity manager.
 *
 * @param entityManager Reference to the entity manager that manages entities
 *                      and their components.
 */
Box::Box(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

/**
 * @brief Updates the Box components based on their positions.
 *
 * This function iterates over all entities in the entity manager and
 * updates the Box component's position based on the Position component's
 * coordinates. If a Box component and its corresponding Position component
 * exist for an entity, the Box's coordinates are set to the Position's
 * coordinates.
 *
 * @param dt The time delta since the last update, used for time-based
 *           updates (not utilized in this implementation).
 */
void Box::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto box = m_entityManager.getComponent<component::Box>(i);
        auto position = m_entityManager.getComponent<component::Position>(i);

        if (box && position) {
            box->x = position->x;
            box->y = position->y;
        }
    }
}

}
