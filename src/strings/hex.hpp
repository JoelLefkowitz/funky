#ifndef FUNKY_STRINGS_HEX_HPP
#define FUNKY_STRINGS_HEX_HPP

#include <cstddef>
#include <string>

namespace funky {
    // hex: int → size_t → std::string
    std::string hex(int n, size_t length);

    // parse_hex: std::string → int
    int parse_hex(const std::string &str);
}

#endif
