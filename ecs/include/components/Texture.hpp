#ifndef TEXTURECOMPONENT_HPP
#define TEXTURECOMPONENT_HPP

#include <string>

#include "Component.hpp"
#include "display/IDisplay.hpp"

namespace component {

struct Texture : public Component {
    std::shared_ptr<display::ITexture> texture;

    Texture(std::shared_ptr<display::ITexture> &texture)
        : texture(texture)
    {
    }
};

}

#endif // TEXTURECOMPONENT_HPP