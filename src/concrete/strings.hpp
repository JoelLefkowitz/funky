#ifndef FUNKY_CONCRETE_STRINGS_HPP
#define FUNKY_CONCRETE_STRINGS_HPP

#include <cstddef>
#include <string>
#include <vector>

namespace funky {
    // starts_with ≔ std::string → std::string → bool
    bool starts_with(const std::string &str, const std::string &prefix);

    // ends_with ≔ std::string → std::string → bool
    bool ends_with(const std::string &str, const std::string &suffix);

    // reverse ≔ std::string → std::string
    std::string reverse(const std::string &str);

    // pad ≔ std::string → size_t → std::string
    std::string pad(const std::string &str, size_t size);

    // truncate ≔ std::string → size_t → std::string → std::string
    std::string truncate(
        const std::string &str,
        size_t limit,
        const std::string &ellipsis = "..."
    );

    // uppercase ≔ std::string → std::string
    std::string uppercase(const std::string &str);

    // lowercase ≔ std::string → std::string
    std::string lowercase(const std::string &str);

    // split ≔ std::string → std::string → std::vector<std::string>
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter
    );

    // join ≔ std::vector<std::string> → std::string → std::string
    std::string join(
        const std::vector<std::string> &strings,
        const std::string &delimiter = ""
    );

    // chunk ≔ std::string → size_t → std::vector<std::string>
    std::vector<std::string> chunk(const std::string &str, size_t size);

    // without_substrings ≔ std::string → std::vector<std::string> → std::string
    std::string without_substrings(
        const std::string &str,
        const std::vector<std::string> &substr
    );

    // format_hex ≔ int → size_t → std::string
    std::string format_hex(int n, size_t length = 6UL);

    // parse_hex ≔ std::string → int
    int parse_hex(const std::string &str);
}

#endif
