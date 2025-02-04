#ifndef FUNKY_STRINGS_STRINGS_HPP
#define FUNKY_STRINGS_STRINGS_HPP

#include <cstddef>
#include <string>
#include <vector>

namespace funky {
    // reverse_copy ≔ std::string → std::string
    std::string reverse_copy(const std::string &str);

    // pad ≔ std::string → size_t → std::string
    std::string pad(const std::string &str, size_t size);

    // chunk ≔ std::string → size_t → std::vector<std::string>
    std::vector<std::string> chunk(const std::string &str, size_t size);

    // split ≔ std::string → std::string → std::vector<std::string>
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter
    );

    // starts_with ≔ std::string → std::string → bool
    bool starts_with(const std::string &str, const std::string &prefix);

    // ends_with ≔ std::string → std::string → bool
    bool ends_with(const std::string &str, const std::string &suffix);

    // uppercase ≔ std::string → std::string
    std::string uppercase(const std::string &str);

    // lowercase ≔ std::string → std::string
    std::string lowercase(const std::string &str);

    // truncate ≔ std::string → size_t → std::string → std::string
    std::string truncate(
        const std::string &str,
        size_t limit,
        const std::string &ellipsis = "..."
    );

    // join ≔ std::vector<std::string> → std::string → std::string
    std::string join(
        const std::vector<std::string> &strings,
        const std::string &delimiter = ""
    );

    // remove_substrings ≔ std::string → std::vector<std::string> → std::string
    std::string remove_substrings(
        const std::string &str,
        const std::vector<std::string> &substr
    );
}

#endif
