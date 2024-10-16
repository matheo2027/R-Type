#ifndef ICLIENT_HPP
#define ICLIENT_HPP

#include <SFML/Network.hpp>
#include <vector>

class IClient {
public:
    virtual ~IClient() = default;
    virtual void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) = 0;
    virtual void receive() = 0;
};

#endif // ICLIENT_HPP