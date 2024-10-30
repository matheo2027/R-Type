#ifndef SERVER_HPP
#define SERVER_HPP

#include "IServer.hpp"

/**
 * @class Server
 * @brief Implements the IServer interface for handling UDP communication.
 *
 * The Server class manages the UDP socket for sending and receiving messages.
 */
class Server : public IServer
{
public:
    /**
     * @brief Constructs a Server instance with the specified port.
     * @param port The port number to bind the server socket.
     */
    Server(unsigned short port);

    /**
     * @brief Sends a message to the specified recipient.
     * @param message A vector of characters representing the message to be sent.
     * @param recipient The IP address of the recipient.
     * @param port The port number of the recipient.
     */
    void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) override;

    /**
     * @brief Receives incoming messages.
     * This method listens for incoming messages on the bound socket and processes them accordingly.
     */
    void receive() override;

private:
    sf::UdpSocket socket; ///< The UDP socket used for communication.
    unsigned short port;   ///< The port number used for the server.
};

#endif // SERVER_HPP
