#ifndef FUNKY_IMPLEMENTATIONS_STRINGS_HEX_HPP
#define FUNKY_IMPLEMENTATIONS_STRINGS_HEX_HPP

#include <cstddef>
#include <string>

namespace funky {
    std::string hex(int n, size_t length = 0);

    int parse_hex(const std::string &str);
} // namespace functional

#endif
