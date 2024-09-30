#include "client.hpp"

int main()
{
    try {
        asio::io_context ioContext;
        Client client(ioContext, "127.0.01", 8080);
        client.start();
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    }

    return 0;
}