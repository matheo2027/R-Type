#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "Component.hpp"

namespace component
{

struct Health : public Component {
    int max;
    int current;

    Health(int max, int current) : max(max), current(current) {}
};

}

#endif // HEALTH_HPP
