#include "utils.hpp"
#include <sstream>

Request parse_request(const std::string& raw_request) {
    Request req;
    std::istringstream iss(raw_request);
    std::string version;

    iss >> req.method >> req.path >> version;

    std::string line;
    std::getline(iss, line);

    while (std::getline(iss, line)) {
        if (line.empty() || line == "\r") break;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        auto colon = line.find(':');
        if (colon != std::string::npos) {
            std::string key = line.substr(0, colon);
            std::string value = line.substr(colon + 2);
            req.headers[key] = value;
        }
    }

    auto it = req.headers.find("Content-Length");
    if (it != req.headers.end()) {
        int len = std::stoi(it->second);
        if (len > 0) {
            req.body.resize(len);
            iss.read(&req.body[0], len);
        }
    }

    return req;
}
