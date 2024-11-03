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

#ifndef TEXTURESERVER_HPP
#define TEXTURESERVER_HPP

#include <string>
#include <memory>

#include "Component.hpp"
#include "display/IDisplay.hpp"

namespace component {

/**
 * @brief The Texture component.
 *
 * The Texture component holds the path to the texture file used for rendering an entity.
 * It to send to the client the path of the texture.
 */
struct TextureServer : public Component {
    /// The path to the texture file.
    std::string path;

    /**
     * @brief Constructs a Texture instance.
     *
     * @param path The path to the texture file.
     */
    TextureServer(const std::string &path) : Component(), path(path) {}
};

} // namespace component

#endif // TEXTURESERVER_HPP
