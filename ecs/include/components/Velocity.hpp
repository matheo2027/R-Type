#ifndef VELOCITYCOMPONENT_HPP
#define VELOCITYCOMPONENT_HPP

/**
 * @namespace component
 * Namespace for all component-related classes and structures.
 */

namespace component {

/**
 * @struct Velocity
 * @brief Represents the velocity of an entity in 2D space.
 *
 * This structure is used to define the velocity of an entity,
 * encapsulating the horizontal (vx) and vertical (vy) components
 * of the velocity vector. It is derived from the Component base class.
 */
struct Velocity : public Component {
    float vx; ///< The horizontal velocity component (along the x-axis).
    float vy; ///< The vertical velocity component (along the y-axis).

    /**
     * @brief Constructs a Velocity instance.
     *
     * @param vx The horizontal velocity component (default is 0).
     * @param vy The vertical velocity component (default is 0).
     */
    Velocity(float vx = 0, float vy = 0) : Component(), vx(vx), vy(vy) {}
};

}

#endif // VELOCITYCOMPONENT_HPP
