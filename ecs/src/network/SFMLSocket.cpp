#include "network/SFMLSocket.hpp"

namespace network
{

IPacket &SFMLPacket::operator<<(int data)
{
    packet << data;
    return *this;
}

IPacket &SFMLPacket::operator<<(float data)
{
    packet << data;
    return *this;
}

IPacket &SFMLPacket::operator<<(bool data)
{
    packet << data;
    return *this;
}

IPacket &SFMLPacket::operator<<(const std::string &data)
{
    packet << data;
    return *this;
}

IPacket &SFMLPacket::operator>>(int &data)
{
    packet >> data;
    return *this;
}

IPacket &SFMLPacket::operator>>(float &data)
{
    packet >> data;
    return *this;
}

IPacket &SFMLPacket::operator>>(bool &data)
{
    packet >> data;
    return *this;
}

IPacket &SFMLPacket::operator>>(std::string &data)
{
    packet >> data;
    return *this;
}

void SFMLPacket::clear()
{
    packet.clear();
}

bool SFMLSocket::bind()
{
    return m_socket.bind(sf::Socket::AnyPort) == sf::Socket::Done;
}

bool SFMLSocket::bind(unsigned short port)
{
    return m_socket.bind(port) == sf::Socket::Done;
}

void SFMLSocket::unbind()
{
    m_socket.unbind();
}

bool SFMLSocket::send(IPacket &packet, const IAddress &address)
{
    auto &sfmlAddress = static_cast<const SFMLAddress &>(address);
    auto &sfmlPacket = static_cast<SFMLPacket &>(packet);

    return m_socket.send(sfmlPacket.packet, sfmlAddress.address, sfmlAddress.port) == sf::Socket::Done;
}

bool SFMLSocket::receive(IPacket &packet, IAddress &address)
{
    auto &sfmlAddress = static_cast<SFMLAddress &>(address);
    auto &sfmlPacket = static_cast<SFMLPacket &>(packet);

    sf::IpAddress ip;
    unsigned short port;
    if (m_socket.receive(sfmlPacket.packet, ip, port) == sf::Socket::Done) {
        sfmlAddress.address = ip;
        sfmlAddress.port = port;
        return true;
    }

    return false;
}

void SFMLSocket::setBlocking(bool blocking)
{
    m_socket.setBlocking(blocking);
}

bool SFMLSocket::isBlocking() const
{
    return m_socket.isBlocking();
}

IAddress SFMLSocket::createAddress(const std::string &address, unsigned short port)
{
    SFMLAddress sfmlAddress;
    sfmlAddress.address = address;
    sfmlAddress.port = port;
    return sfmlAddress;
}

std::unique_ptr<IPacket> SFMLSocket::createPacket()
{
    auto packet = std::make_unique<SFMLPacket>();
    packet->packet = sf::Packet();
    return packet;
}

}

