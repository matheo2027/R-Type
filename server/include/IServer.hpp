#ifndef ISERVER_HPP
#define ISERVER_HPP

#include <SFML/Network.hpp>
#include <vector>

class IServer
{
public:
    virtual ~IServer() = default;
    virtual void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) = 0;
    virtual void receive() = 0;
};

#endif // ISERVER_HPP