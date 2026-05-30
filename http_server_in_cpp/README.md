# Basic HTTP Server in C++

This project implements a simple HTTP server in C++ that listens for incoming requests and responds with the requested path. It is a direct port of the C version, rewritten using idiomatic C++ features.

## Features

- Listens on a given IP and port (default: `127.0.0.1:8080`)
- Handles one request at a time
- Parses HTTP GET requests and responds with the requested path

---

## Requirements

- GCC or Clang (any C++ compiler that supports C++17)
- Unix-like environment (Linux/macOS)

---

## How to Run

### 1. Clone the Repository

```bash
git clone
cd http_server_in_cpp
```

### 2. Build the project

Compile code using the Makefile.

Run `make` in the http_server_in_cpp directory.

### 3. Execute compiled code

```bash
./build/http_server
```

---

### Future Improvements

- Add support for concurrent requests using threads
- Implement more HTTP methods (POST, HEAD, etc.)
- Return HTML or JSON responses
- Add logging
