#include <stdio.h>
#include "server.h"

int main() {
    const char* ip = "127.0.0.1";
    int port = 8080;

    printf("Starting server at %s:%d...\n", ip, port);
    start_server(ip, port);

    return 0;
}