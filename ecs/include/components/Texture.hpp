/**
 * @file TextureComponent.hpp
 * @brief Defines the Texture component for the Entity-Component-System (ECS) architecture.
 *
 * This file contains the declaration of the Texture component, which holds a
 * reference to a texture used for rendering entities in the game.
 * The Texture component inherits from the base Component class.
 *
 * @author Your Name
 * @date YYYY-MM-DD
 */

#ifndef TEXTURECOMPONENT_HPP
#define TEXTURECOMPONENT_HPP

#include <string>
#include <memory>

#include "Component.hpp"
#include "display/IDisplay.hpp"

namespace component {

/**
 * @struct Texture
 * @brief Represents a texture component in the ECS.
 *
 * The Texture struct holds a shared pointer to an ITexture interface, allowing
 * for flexible texture management and rendering.
 */
struct Texture : public Component {
    /// Shared pointer to the texture to be used.
    std::shared_ptr<display::ITexture> texture;

    /**
     * @brief Constructs a Texture component with a given texture.
     *
     * @param texture A shared pointer to an ITexture object.
     */
    Texture(std::shared_ptr<display::ITexture> &texture)
        : texture(texture)
    {
    }
};

} // namespace component

#endif // TEXTURECOMPONENT_HPP
