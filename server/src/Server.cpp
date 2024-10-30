/**
 * @file Server.hpp
 * @brief Declaration of the Server class for handling network communications.
 */

#include "../include/Server.hpp"
#include <iostream>

/**
 * @class Server
 * @brief A class that represents a server for network communication using SFML.
 *
 * The Server class is responsible for binding to a specified port, sending messages to clients,
 * and receiving messages from clients.
 */
Server::Server(unsigned short port) : port(port)
{
    if (socket.bind(port) != sf::Socket::Done)
    {
        std::cerr << "Error binding socket to port " << port << std::endl;
        exit(1);
    }
    std::cout << "Server listening on port " << port << "..." << std::endl;
}

/**
 * @brief Sends a message to a specified recipient.
 * @param message A vector containing the message data to be sent.
 * @param recipient The IP address of the recipient.
 * @param port The port number to send the message to.
 *
 * This function sends the specified message to the given recipient using the bound socket.
 * If the message cannot be sent, an error message is printed to standard error.
 */
void Server::send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port)
{
    if (socket.send(message.data(), message.size(), recipient, port) != sf::Socket::Done)
    {
        std::cerr << "Error sending message" << std::endl;
    }
}

/**
 * @brief Receives messages from clients in a loop.
 *
 * This function continuously listens for incoming messages. When a message is received,
 * it is printed along with the sender's IP address and port. If there is an error receiving
 * data, an error message is printed to standard error.
 */
void Server::receive()
{
    while (true)
    {
        char buffer[128];
        std::size_t received;
        sf::IpAddress sender;
        unsigned short port;
        if (socket.receive(buffer, sizeof(buffer), received, sender, port) != sf::Socket::Done)
        {
            std::cerr << "Error receiving data" << std::endl;
            continue;
        }

        std::vector<char> message(buffer, buffer + received);
        std::cout << "Message received from " << sender << ":" << port << std::endl;
    }
}
