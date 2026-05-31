#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <unordered_map>

struct Request {
    std::string method;
    std::string path;
    std::string body;
    std::unordered_map<std::string, std::string> headers;
};

Request parse_request(const std::string& raw_request);

#endif
