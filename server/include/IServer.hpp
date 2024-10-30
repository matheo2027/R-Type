/**
 * @file IServer.hpp
 * @brief Interface for server communication.
 *
 * This file defines the IServer interface, which provides methods for sending and receiving messages
 * over a network using SFML.
 */

#ifndef ISERVER_HPP
#define ISERVER_HPP

#include <SFML/Network.hpp>
#include <vector>

/**
 * @class IServer
 * @brief An interface for server functionalities.
 *
 * The IServer interface defines the essential methods for a server, allowing for sending and
 * receiving messages. Any class that implements this interface must provide concrete implementations
 * for these methods.
 */
class IServer
{
public:
    /// Destructor
    virtual ~IServer() = default;

    /**
     * @brief Sends a message to a specified recipient.
     *
     * @param message The message to be sent as a vector of characters.
     * @param recipient The IP address of the recipient.
     * @param port The port number to send the message to.
     */
    virtual void send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) = 0;

    /**
     * @brief Receives a message from a client.
     *
     * This method is responsible for handling incoming messages. The implementation should define
     * how the message is processed once received.
     */
    virtual void receive() = 0;
};

#endif // ISERVER_HPP
