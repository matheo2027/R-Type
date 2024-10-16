#include "../include/Client.hpp"
#include <iostream>

Client::Client() {

}

void Client::send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) {
    if (socket.send(message.data(), message.size(), recipient, port) != sf::Socket::Done) {
        std::cerr << "Erreur lors de l'envoi du message" << std::endl;
    }
}

void Client::receive() {
    char buffer[128];
    std::size_t received;
    sf::IpAddress sender;
    unsigned short port;

    if (socket.receive(buffer, sizeof(buffer), received, sender, port) != sf::Socket::Done) {
        std::cerr << "Erreur lors de la réception du message" << std::endl;
    } else {
        std::vector<char> message(buffer, buffer + received);
        std::cout << "Message reçu de " << sender << " : " << std::endl;
    }
}