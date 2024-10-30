#include "systems/Render.hpp"
#include <iostream>

namespace systems
{

/**
 * @class Render
 * @brief A system responsible for rendering entities on the display.
 *
 * The Render class iterates through all entities managed by the EntityManager,
 * retrieves their position and texture components, and uses the provided display
 * interface to draw the entities on the screen.
 */
class Render {
public:
    /**
     * @brief Constructs a Render system.
     *
     * @param entityManager Reference to the EntityManager for managing entities.
     * @param display Reference to the display interface for rendering.
     */
    Render(ecs::EntityManager &entityManager, display::IDisplay &display);

    /**
     * @brief Updates the rendering system.
     *
     * This method is called to render all entities on the display.
     * It retrieves the position and texture components of each entity and
     * draws them at the specified coordinates.
     *
     * @param dt The time delta since the last update (not used).
     */
    void update(float dt);

private:
    ecs::EntityManager &m_entityManager; ///< Reference to the EntityManager.
    display::IDisplay &m_display;         ///< Reference to the display interface.
};

} // namespace systems
