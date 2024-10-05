#ifndef NETWORKCOMPONENT_HPP
#define NETWORKCOMPONENT_HPP

namespace component {

struct Network {
    int networkId;

    Network(int networkId = 0) : networkId(networkId) {}
};

}

#endif // NETWORKCOMPONENT_HPP