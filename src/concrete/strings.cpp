#include "strings.hpp"
#include "../generics/iterables.tpp"
#include "vectors.tpp"
#include <algorithm>
#include <cstddef>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

bool funky::starts_with(const std::string &str, const std::string &prefix) {
    return str.length() >= prefix.length() && str.substr(0, prefix.length()) == prefix;
}

bool funky::ends_with(const std::string &str, const std::string &suffix) {
    return str.length() >= suffix.length() && str.substr(str.length() - suffix.length(), str.length()) == suffix;
}

std::string funky::reverse(const std::string &str) {
    std::string copy = str;
    std::reverse(copy.begin(), copy.end());
    return copy;
}

std::string funky::pad(const std::string &str, size_t size) {
    return size > str.size() ? str + std::string(size - str.size(), ' ') : str;
}

std::string funky::truncate(const std::string &str, size_t limit, const std::string &ellipsis) {
    if (str.size() <= limit) {
        return str;
    }

    auto width = limit > ellipsis.size() ? limit - ellipsis.size() : 0;
    return str.substr(0, width) + ellipsis;
}

std::string funky::uppercase(const std::string &str) {
    std::function<char(char)> upper = [](auto x) {
        return std::toupper(x);
    };
    return funky::map(upper, str);
}

std::string funky::lowercase(const std::string &str) {
    std::function<char(char)> lower = [](auto x) {
        return std::tolower(x);
    };
    return funky::map(lower, str);
}

std::vector<std::string> funky::split(const std::string &str, const std::string &delimiter) {
    if (str.empty()) {
        return {str};
    }

    if (delimiter.empty()) {
        auto singleton = [](auto x) {
            return std::string(1, x);
        };

        return map<std::vector<std::string>>(singleton, str);
    }

    size_t pos = 0;

    std::string copy = str;

    std::vector<std::string> chunks;

    while ((pos = copy.find(delimiter, 0)) != std::string::npos) {
        chunks.push_back(copy.substr(0, pos));
        copy.replace(0, pos + delimiter.length(), "");
    }

    if (!copy.empty() || ends_with(str, delimiter)) {
        chunks.push_back(copy);
    }

    return chunks;
}

std::string funky::join(const std::vector<std::string> &strings, const std::string &delimiter) {
    std::function<std::string(const std::string &, const std::string &)> append =
        [&delimiter](const auto &acc, const auto &x) {
            return acc + x + delimiter;
        };

    auto joined = funky::fold<std::string>(append, "", strings);

    return strings.empty() ? "" : joined.substr(0, joined.size() - delimiter.size());
}

std::vector<std::string> funky::chunk(const std::string &str, size_t size) {
    return map<std::vector<std::string>>(
        [size, &str](auto x) {
            return str.substr(size * x, size);
        },
        funky::range(size > 0 ? str.length() / size : 0)
    );
}

std::string funky::without_substrings(const std::string &str, const std::vector<std::string> &substrs) {
    std::string copy = str;

    for (size_t i = 0; i < copy.size();) {
        bool erased = false;

        for (const auto &x : substrs) {
            if (copy.substr(i, x.size()) == x) {
                copy.erase(i, x.size());
                erased = true;
            }
        }

        if (!erased) {
            i++;
        }
    }

    return copy;
}

std::string funky::format_hex(int n, size_t length) {
    std::stringstream stream;
    stream << std::hex << n;
    auto str = stream.str();

    auto padding = length > str.length() ? length - str.length() : 0;
    return std::string(padding, '0') + str;
}

int funky::parse_hex(const std::string &str) {
    std::stringstream ss;
    ss << std::hex << str;

    int parsed = 0;
    ss >> parsed;
    return parsed;
}
