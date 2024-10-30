/**
 * @file Client.cpp
 * @brief Implementation of the Client class for network communication.
 *
 * This file contains the implementation of the Client class, which is responsible
 * for handling socket communication. It allows sending and receiving messages
 * over a specified port.
 *
 * @include <SFML/Network.hpp>
 * @include <vector>
 * @include <iostream>
 */

#include "../include/Client.hpp"
#include <iostream>

/**
 * @brief Constructs a Client object and binds it to the specified port.
 *
 * This constructor attempts to bind the socket to the given port. If the binding
 * fails, an error message is printed to the standard error stream, and the program
 * exits with a status of 1.
 *
 * @param port The port number to which the socket will be bound.
 */
Client::Client(int port) {
    if (socket.bind(port) != sf::Socket::Done) {
        std::cerr << "Error binding socket to port " << port << std::endl;
        exit(1);
    }
    std::cout << "Client listening on port " << port << "..." << std::endl;
}

/**
 * @brief Sends a message to a specified recipient.
 *
 * This function sends a message to the specified recipient IP address and port.
 * If the sending fails, an error message is printed to the standard error stream.
 *
 * @param message A vector of characters representing the message to be sent.
 * @param recipient The IP address of the recipient.
 * @param port The port number of the recipient.
 */
void Client::send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) {
    if (socket.send(message.data(), message.size(), recipient, port) != sf::Socket::Done) {
        std::cerr << "Error sending message" << std::endl;
    }
}

/**
 * @brief Receives a message from a sender.
 *
 * This function attempts to receive a message into a buffer. If the reception
 * is successful, the received message is printed along with the sender's IP address.
 * Otherwise, an error message is printed to the standard error stream.
 */
void Client::receive() {
    char buffer[128];
    std::size_t received;
    sf::IpAddress sender;
    unsigned short port;

    if (socket.receive(buffer, sizeof(buffer), received, sender, port) != sf::Socket::Done) {
        std::cerr << "Error receiving message" << std::endl;
    } else {
        std::vector<char> message(buffer, buffer + received);
        std::cout << "Message received from " << sender << " : " << std::endl;
    }
}
