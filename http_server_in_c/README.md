# Basic HTTP Server in C

This project implements a simple HTTP server in C that listens for incoming requests and responds with the requested path. It is built as a learning exercise in socket programming and low-level networking.

## Features

- Listens on a given IP and port (default: `127.0.0.1:8080`)
- Handles one request at a time
- Parses HTTP GET requests and responds with the requested path

---

## Requirements

- GCC or Clang (any C compiler that supports C11)
- Unix-like environment (Linux/macOS)

---

## How to Run

### 1. Clone the Repository

```bash
git clone
cd http_server_in_c
```

### 2. Build the project
Compile code use Makefile.  

Run ``` make ``` in http_server_in_c directory

### 3. Execute compiled code
```./build/http_server```

---

### Future Improvements
- Add support for concurrent requests using threads or select()
- Implement more HTTP methods (POST, HEAD, etc.)
- Return HTML or JSON responses
- Add loggin

Above improvements are not in specific order and may change as I understand the process and language better