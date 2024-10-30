#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP

#include "components/Component.hpp"

namespace component {

/**
 * @brief Represents a position in a 2D space.
 *
 * The Position struct inherits from the Component class and stores
 * the x and y coordinates of an entity in the game.
 * This component can be used to define the position of game entities
 * in a 2D environment.
 */
struct Position : public Component {
    /// The x-coordinate of the position.
    float x;

    /// The y-coordinate of the position.
    float y;

    /**
     * @brief Constructs a Position object with the specified coordinates.
     *
     * @param x The x-coordinate (default is 0).
     * @param y The y-coordinate (default is 0).
     */
    Position(float x = 0, float y = 0) : Component(), x(x), y(y) {}
};

} // namespace component

#endif // POSITIONCOMPONENT_HPP
