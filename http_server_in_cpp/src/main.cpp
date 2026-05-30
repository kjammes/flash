#include <iostream>
#include "server.hpp"

int main() {
    std::string ip = "127.0.0.1";
    int port = 8080;

    std::cout << "Starting server at " << ip << ":" << port << "...\n";
    start_server(ip, port);

    return 0;
}
