#ifndef HEX_HPP
#define HEX_HPP

#include <cstddef>
#include <string>

namespace functional {
    std::string hex(int n, size_t length = 0);

    int parse_hex(const std::string &str);
} // namespace functional

#endif
