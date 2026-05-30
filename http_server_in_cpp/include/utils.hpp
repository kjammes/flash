#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

std::string extract_path(const std::string& request);
std::string extract_method(const std::string& request);

#endif
