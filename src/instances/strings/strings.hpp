#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <cstddef>
#include <string>
#include <vector>

namespace functional {
    std::string reverse_copy(const std::string &str);

    std::string pad(const std::string &str, size_t size);

    std::vector<std::string> chunk(const std::string &str, size_t size);
    std::vector<std::string> split(const std::string &str, const std::string &delimiter = "\n");

    bool starts_with(const std::string &str, const std::string &prefix);
    bool ends_with(const std::string &str, const std::string &suffix);

    std::string uppercase(const std::string &str);
    std::string lowercase(const std::string &str);

    std::string truncate(const std::string &str, size_t limit, const std::string &ellipsis = "...");

    std::string join(const std::vector<std::string> &strings, const std::string &delimeter);

    std::string remove_substrings(const std::string &str, const std::vector<std::string> &substr);
} // namespace functional

#endif
