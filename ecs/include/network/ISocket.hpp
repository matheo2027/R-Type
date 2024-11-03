#pragma once

#include <string>
#include <memory>

const static int MAX_PACKET_PER_FRAME = 1000;
const static float SEND_INTERVAL = 1.0f/60.0f;
const static float TIMEOUT = 5.0f;

namespace network
{

struct IAddress
{
};

struct IPacket
{
    virtual void clear() = 0;
    virtual IPacket &operator<<(int data) = 0;
    virtual IPacket &operator<<(float data) = 0;
    virtual IPacket &operator<<(bool data) = 0;
    virtual IPacket &operator<<(const std::string &data) = 0;
    virtual IPacket &operator>>(int &data) = 0;
    virtual IPacket &operator>>(float &data) = 0;
    virtual IPacket &operator>>(bool &data) = 0;
    virtual IPacket &operator>>(std::string &data) = 0;
};

class ISocket
{
    public:
        ISocket() = default;
        virtual ~ISocket() = default;

        virtual bool bind() = 0;
        virtual bool bind(unsigned short port) = 0;
        virtual void unbind() = 0;

        virtual bool send(IPacket &packet, const IAddress &address) = 0;
        virtual bool receive(IPacket &packet, IAddress &address) = 0;

        virtual void setBlocking(bool blocking) = 0;
        virtual bool isBlocking() const = 0;

        virtual IAddress createAddress(const std::string &address="", unsigned short port=0) = 0;
        virtual std::unique_ptr<IPacket> createPacket() = 0;
};

}