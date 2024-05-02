#ifndef FUNCTIONAL_INSTANCES_STRINGS_HEX_HPP
#define FUNCTIONAL_INSTANCES_STRINGS_HEX_HPP

#include <cstddef>
#include <string>

namespace functional {
    std::string hex(int n, size_t length = 0);

    int parse_hex(const std::string &str);
} // namespace functional

#endif
