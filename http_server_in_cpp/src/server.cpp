#include "server.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

constexpr int BUFFER_SIZE = 4096;

void start_server(const std::string& ip, int port) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::perror("Socket creation failed");
        std::exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::perror("Bind failed");
        close(server_fd);
        std::exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        std::perror("Listen failed");
        close(server_fd);
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on " << ip << ":" << port << "\n";

    while (true) {
        client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd < 0) {
            std::perror("Accept failed");
            continue;
        }

        read(client_fd, buffer, BUFFER_SIZE - 1);
        buffer[BUFFER_SIZE - 1] = '\0';
        std::string path = extract_path(buffer);

        std::string response = "HTTP/1.1 200 OK\r\n\r\nRequested path: " + path + "\r\n";
        write(client_fd, response.c_str(), response.size());

        close(client_fd);
    }

    close(server_fd);
}
