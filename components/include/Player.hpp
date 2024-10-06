#ifndef PLAYERCOMPONENT_HPP
#define PLAYERCOMPONENT_HPP

namespace component {

struct Player {
    int playerId;

    Player(int playerId = 0) : playerId(playerId) {}
};

}

#endif // PLAYERCOMPONENT_HPP