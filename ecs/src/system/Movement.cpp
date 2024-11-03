/**
 * @file Movement.hpp
 * @brief Contains the Movement system for updating entity positions based on their velocities.
 */

#include "systems/Movement.hpp"
#include <iostream>
#include <cmath>

namespace systems
{

/**
 * @class Movement
 * @brief The Movement class is responsible for updating the positions of entities based on their velocities.
 *
 * This system iterates through all entities managed by the EntityManager and updates their positions
 * according to their velocity components. It assumes that each entity may have a Position and Velocity component.
 */
Movement::Movement(ecs::EntityManager &entityManager)
    : m_entityManager(entityManager)
{
}

/**
 * @brief Updates the positions of entities based on their velocities.
 * @param dt The delta time (time since the last update) used to calculate the new position.
 *
 * This method loops through all entities in the EntityManager and checks for their Position and
 * Velocity components. If both components are present, it updates the position of the entity
 * using the velocity values multiplied by the delta time.
 */
void Movement::update(float dt)
{
    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto position = m_entityManager.getComponent<component::Position>(i);
        auto velocity = m_entityManager.getComponent<component::Velocity>(i);
        auto pattern = m_entityManager.getComponent<component::Pattern>(i);

        if (position && velocity) {
            if (pattern) {
                pattern->elapsedTime += dt;
                velocity->vx = pattern->directionX * pattern->speed;
                velocity->vy = pattern->directionY * pattern->speed + pattern->amplitude * std::sin(pattern->frequency * pattern->elapsedTime);
            }
            position->x += velocity->vx * dt;
            position->y += velocity->vy * dt;


        }
    }
}

}
