#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "IClient.hpp"

class Client : public IClient {
public:
    Client(int port);
    

    void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) override;
    void receive() override;

private:
    sf::UdpSocket socket;
};

#endif // CLIENT_HPP