#include "hex.hpp"
#include <cstddef>
#include <sstream>
#include <string>

std::string functional::hex(int n, size_t length) {
    std::stringstream stream;
    stream << std::hex << n;
    auto str = stream.str();

    auto padding = length > str.length() ? length - str.length() : 0;
    return std::string("0", padding) + str;
}

int functional::parse_hex(const std::string &str) {
    std::stringstream ss;
    ss << std::hex << str;

    int parsed = 0;
    ss >> parsed;
    return parsed;
}
