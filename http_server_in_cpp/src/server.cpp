#include "server.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <functional>
#include <unordered_map>

constexpr int BUFFER_SIZE = 4096;

static std::string handle_get(const Request& req, int port) {
    return "HTTP/1.1 200 OK\r\n\r\nGET " + req.path + " on port " + std::to_string(port) + "\r\n";
}

static std::string handle_post(const Request& req, int port) {
    return "HTTP/1.1 200 OK\r\n\r\nPOST " + req.path + " on port " + std::to_string(port) + "\r\nBody: " + req.body + "\r\n";
}

static std::string handle_put(const Request& req, int port) {
    return "HTTP/1.1 200 OK\r\n\r\nPUT " + req.path + " on port " + std::to_string(port) + "\r\nBody: " + req.body + "\r\n";
}

static std::string handle_patch(const Request& req, int port) {
    return "HTTP/1.1 200 OK\r\n\r\nPATCH " + req.path + " on port " + std::to_string(port) + "\r\nBody: " + req.body + "\r\n";
}

static std::string handle_delete(const Request& req, int port) {
    return "HTTP/1.1 200 OK\r\n\r\nDELETE " + req.path + " on port " + std::to_string(port) + "\r\n";
}

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
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

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

    const std::unordered_map<std::string, std::function<std::string(const Request&, int)>> handlers = {
        {"GET", handle_get},
        {"POST", handle_post},
        {"PUT", handle_put},
        {"PATCH", handle_patch},
        {"DELETE", handle_delete},
    };

    while (true) {
        client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd < 0) {
            std::perror("Accept failed");
            continue;
        }

        ssize_t bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
        if (bytes_read <= 0) {
            close(client_fd);
            continue;
        }
        buffer[bytes_read] = '\0';

        Request req = parse_request(buffer);
        auto it = handlers.find(req.method);
        std::string response;
        if (it != handlers.end()) {
            response = it->second(req, port);
        } else {
            response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        }

        write(client_fd, response.c_str(), response.size());
        close(client_fd);
    }

    close(server_fd);
}
