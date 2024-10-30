/**
 * @file Render.hpp
 * @brief Contains the Render class responsible for rendering entities on the display.
 *
 * This file includes the definition and implementation of the Render class,
 * which manages the drawing of entities to the display based on their
 * position and texture components.
 */

#include "systems/Render.hpp"
#include <iostream>

namespace systems
{

/**
 * @brief Constructs a Render object.
 *
 * This constructor initializes the Render class with the given entity manager
 * and display. It stores references to the entity manager and display for
 * rendering purposes.
 *
 * @param entityManager A reference to the ecs::EntityManager that manages
 *                      all entities and their components.
 * @param display A reference to the display::IDisplay that handles rendering
 *                to the screen.
 */
Render::Render(ecs::EntityManager &entityManager, display::IDisplay &display)
    : m_entityManager(entityManager), m_display(display)
{
}

/**
 * @brief Updates the rendering process.
 *
 * This method is called to update the rendering of all entities in the
 * entity manager. It retrieves the position and texture components for each
 * entity and calls the display's draw method if both components are present.
 *
 * @param dt The time elapsed since the last update (not used in this method).
 */
void Render::update(float dt)
{
    (void)dt; // Suppress unused parameter warning.

    for (unsigned int i = 0; i < m_entityManager.size(); i++) {
        auto position = m_entityManager.getComponent<component::Position>(i);
        auto texture = m_entityManager.getComponent<component::Texture>(i);

        if (position && texture) {
            m_display.draw(texture->texture, position->x, position->y);
        }
    }
}

} // namespace systems
