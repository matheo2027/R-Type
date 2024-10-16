#include "../include/Server.hpp"
#include <iostream>

Server::Server(unsigned short port) : port(port) {
    if (socket.bind(port) != sf::Socket::Done) {
        std::cerr << "Erreur lors de la liaison du socket au port " << port << std::endl;
        exit(1);
    }
    std::cout << "Le serveur écoute sur le port " << port << "..." << std::endl;
}

void Server::send(const std::vector<char>& message, const sf::IpAddress& recipient, unsigned short port) {
    if (socket.send(message.data(), message.size(), recipient, port) != sf::Socket::Done) {
        std::cerr << "Erreur lors de l'envoi du message" << std::endl;
    }
}

void Server::receive() {
    while (true) {
        char buffer[128];
        std::size_t received;
        sf::IpAddress sender;
        unsigned short port;
        if (socket.receive(buffer, sizeof(buffer), received, sender, port) != sf::Socket::Done) {
            std::cerr << "Erreur lors de la réception des données" << std::endl;
            continue;
        }

        std::vector<char> message(buffer, buffer + received);
        std::cout << "Message reçu de " << sender << ":" << port << std::endl;
    }
}