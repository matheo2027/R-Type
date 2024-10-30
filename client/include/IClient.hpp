/**
 * @file IClient.hpp
 * @brief Interface definition for a client responsible for network communication.
 */

#ifndef ICLIENT_HPP
#define ICLIENT_HPP

#include <SFML/Network.hpp>
#include <vector>

/**
 * @class IClient
 * @brief An interface for network client functionalities, enabling sending and receiving of messages.
 *
 * The `IClient` class defines the basic operations required for a network client. It supports
 * message transmission and reception over a specified network protocol.
 */
class IClient {
public:
    /**
     * @brief Virtual destructor for the IClient interface.
     *
     * Ensures derived classes can override and clean up resources properly.
     */
    virtual ~IClient() = default;

    /**
     * @brief Send a message to a specific recipient.
     *
     * This pure virtual function must be implemented by derived classes to send a message
     * to a given IP address and port.
     *
     * @param message The message data to be sent, represented as a vector of characters.
     * @param recipient The IP address of the recipient.
     * @param port The port number on the recipient's machine.
     */
    virtual void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) = 0;

    /**
     * @brief Receive a message.
     *
     * This pure virtual function must be implemented by derived classes to handle
     * incoming messages from the network.
     */
    virtual void receive() = 0;
};

#endif // ICLIENT_HPP
