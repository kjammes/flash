#include "utils.hpp"
#include <sstream>

std::string extract_path(const std::string& request) {
    std::istringstream iss(request);
    std::string method, path, version;
    iss >> method >> path >> version;
    return path;
}

std::string extract_method(const std::string& request) {
    std::istringstream iss(request);
    std::string method;
    iss >> method;
    return method;
}
