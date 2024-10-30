/**
 * @file Client.hpp
 * @brief Declaration of the Client class for handling UDP communication.
 */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "IClient.hpp"

/**
 * @class Client
 * @brief Manages UDP socket communications.
 *
 * The Client class handles sending and receiving UDP messages
 * to specified recipients and ports.
 */
class Client : public IClient {
public:
    /**
     * @brief Constructs a new Client object.
     * @param port The port on which the client will communicate.
     */
    Client(int port);

    /**
     * @brief Sends a UDP message to a specific recipient.
     *
     * @param message The message content to send as a vector of characters.
     * @param recipient The IP address of the recipient.
     * @param port The port number on the recipient's end to which the message is sent.
     */
    void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) override;

    /**
     * @brief Receives a UDP message.
     *
     * This function is a blocking call and waits for an incoming message on the assigned socket.
     */
    void receive() override;

private:
    sf::UdpSocket socket; /**< UDP socket used for sending and receiving messages. */
};

#endif // CLIENT_HPP