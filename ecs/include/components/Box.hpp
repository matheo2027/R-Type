/**
 * @file Box.hpp
 * @brief Defines the Box component for collision detection.
 *
 * This file contains the definition of the Box structure, which represents a
 * rectangular area in a 2D space. The Box structure includes methods for
 * testing collisions with other Box instances.
 */

#ifndef BOX_HPP
#define BOX_HPP

#include "Component.hpp"

namespace component {

/**
 * @struct Box
 * @brief Represents a rectangular area defined by its position and dimensions.
 *
 * The Box structure is derived from the Component class and contains
 * properties for the position and size of the rectangle.
 */
struct Box : public Component {
    int x;      ///< The x-coordinate of the top-left corner of the box.
    int y;      ///< The y-coordinate of the top-left corner of the box.
    int width;  ///< The width of the box.
    int height; ///< The height of the box.

    /**
     * @brief Constructs a Box instance.
     *
     * @param x The x-coordinate of the top-left corner of the box.
     * @param y The y-coordinate of the top-left corner of the box.
     * @param width The width of the box.
     * @param height The height of the box.
     */
    Box(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    /**
     * @brief Tests for collision with another Box.
     *
     * This method checks if the current Box instance collides with
     * another Box instance.
     *
     * @param other The other Box instance to test for collision.
     * @return true if the boxes collide, false otherwise.
     */
    bool testCollision(const Box &other) const {
        return x < other.x + other.width &&
               x + width > other.x &&
               y < other.y + other.height &&
               y + height > other.y;
    }
};

} // namespace component

#endif // BOX_HPP
