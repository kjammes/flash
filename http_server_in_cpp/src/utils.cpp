#include "utils.hpp"
#include <sstream>

std::string extract_path(const std::string& request) {
    std::istringstream iss(request);
    std::string method, path, version;
    iss >> method >> path >> version;
    return path;
}
