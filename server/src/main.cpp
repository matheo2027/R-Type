#include "server.hpp"

int main()
{
    try {
        asio::io_context ioContext;
        Game game(ioContext, 8080);
        game.start();

        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get();

        game.stop();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    return 0;
}