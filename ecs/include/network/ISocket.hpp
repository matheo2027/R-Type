#pragma once

#include <string>
#include <memory>

const static int MAX_PACKET_PER_FRAME = 100;
const static float SEND_INTERVAL = 1.0f/60.0f;

namespace network
{

class ISocket
{
    public:
        ISocket() = default;
        virtual ~ISocket() = default;

        
};

}