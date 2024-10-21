#ifndef SERVER_HPP
#define SERVER_HPP

#include "IServer.hpp"

class Server : public IServer
{
public:
    Server(unsigned short port);
    void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) override;
    void receive() override;

private:
    sf::UdpSocket socket;
    unsigned short port;
};

#endif // SERVER_HPP