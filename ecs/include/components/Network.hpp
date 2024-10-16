#ifndef NETWORKCOMPONENT_HPP
#define NETWORKCOMPONENT_HPP

#include "Component.hpp"

namespace component {

struct Network : public Component {
    int networkId;

    Network(int networkId = 0) : Component(), networkId(networkId) {}
};

}

#endif // NETWORKCOMPONENT_HPP