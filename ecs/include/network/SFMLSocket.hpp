#pragma once

#include <SFML/Network.hpp>

#include "ISocket.hpp"

namespace network
{

struct SFMLAddress : public IAddress
{
    sf::IpAddress address;
    unsigned short port;
};

struct SFMLPacket : public IPacket
{
    IPacket &operator<<(int data) override;
    IPacket &operator<<(float data) override;
    IPacket &operator<<(bool data) override;
    IPacket &operator<<(const std::string &data) override;

    IPacket &operator>>(int &data) override;
    IPacket &operator>>(float &data) override;
    IPacket &operator>>(bool &data) override;
    IPacket &operator>>(std::string &data) override;

    void clear() override;

    sf::Packet packet;

};

class SFMLSocket : public ISocket
{
    public:
        bool bind();
        bool bind(unsigned short port);
        void unbind() override;

        bool send(IPacket &packet, const IAddress &address) override;
        bool receive(IPacket &packet, IAddress &address) override;

        void setBlocking(bool blocking) override;
        bool isBlocking() const override;

        IAddress createAddress(const std::string &address="", unsigned short port=0) override;
        std::unique_ptr<IPacket> createPacket() override;

    private:
        sf::UdpSocket m_socket;

};

}