#include "strings.hpp"
#include "../../generics/foldable/fold.tpp"
#include "../../generics/functor/map.tpp"
#include <algorithm>
#include <cstddef>
#include <functional>
#include <string>
#include <vector>

// iwyu-disable-next-line
#include "../vectors/ranges.tpp"

std::string functional::reverse_copy(const std::string &str) {
    std::string copy = str;
    std::reverse(copy.begin(), copy.end());
    return copy;
}

std::string functional::pad(const std::string &str, size_t size) {
    return size > str.size() ? str + std::string(size - str.size(), ' ') : str;
}

std::vector<std::string> functional::chunk(const std::string &str, size_t size) {
    std::function<std::string(size_t)> slice = [size, &str](auto x) { return str.substr(size * x, size); };

    return functional::map(slice, functional::range(size > 0 ? str.length() / size : 0));
}

std::vector<std::string> functional::split(const std::string &str, const std::string &delimiter) {
    if (str.empty()) {
        return {str};
    }

    if (delimiter.empty()) {
        std::vector<std::string> strs;

        for (auto i = str.begin(); i != str.end(); ++i) {
            strs.emplace_back(1, *i);
        }

        return strs;
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

bool functional::starts_with(const std::string &str, const std::string &prefix) {
    return str.length() >= prefix.length() && str.substr(0, prefix.length()) == prefix;
}

bool functional::ends_with(const std::string &str, const std::string &suffix) {
    return str.length() >= suffix.length() && str.substr(str.length() - suffix.length(), str.length()) == suffix;
}

std::string functional::uppercase(const std::string &str) {
    std::function<char(char)> upper = [](auto x) { return std::toupper(x); };
    return functional::map(upper, str);
}

std::string functional::lowercase(const std::string &str) {
    std::function<char(char)> lower = [](auto x) { return std::tolower(x); };
    return functional::map(lower, str);
}

std::string functional::truncate(const std::string &str, size_t limit, const std::string &ellipsis) {
    if (str.size() <= limit) {
        return str;
    }

    auto width = limit > ellipsis.size() ? limit - ellipsis.size() : 0;
    return str.substr(0, width) + ellipsis;
}

std::string functional::join(const std::vector<std::string> &strings, const std::string &delimiter) {
    std::function<std::string(const std::string &, const std::string &)> append =
        [&delimiter](const auto &acc, const auto &x) { return acc + x + delimiter; };

    auto joined = functional::fold<std::vector<std::string>, std::string, std::string>(append, "", strings);

    return strings.empty() ? "" : joined.substr(0, joined.size() - delimiter.size());
}

std::string functional::remove_substrings(const std::string &str, const std::vector<std::string> &substrs) {
    std::string copy = str;

    for (size_t i = 0; i < copy.size();) {
        bool erased = false;

        for (const auto &substr : substrs) {
            if (copy.substr(i, substr.size()) == substr) {
                copy.erase(i, substr.size());
                erased = true;
            }
        }

        if (!erased) {
            ++i;
        }
    }

    return copy;
}
