#ifndef IMMUTABLE_TPP
#define IMMUTABLE_TPP

#include "../../generics/foldable/fold.tpp"
#include "../../generics/functor/map.tpp"
#include "../numbers/limits.hpp"
#include "elements.hpp"
#include "immutable.hpp"
#include "mutable.tpp"
#include "ranges.tpp"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>

template <typename T>
std::vector<T> functional::unique(const std::vector<T> &vec) {
    std::vector<T> unique;

    for (auto x : vec) {
        if (!contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename T>
std::vector<T> functional::reverse(const std::vector<T> &vec) {
    std::vector<T> copy;

    if (vec.empty()) {
        return copy;
    }

    auto size = --vec.begin();

    for (auto i = --vec.end(); i != size; --i) {
        copy.push_back(*i);
    }

    return copy;
}

template <typename T>
std::vector<T> functional::difference(const std::vector<T> &source, const std::vector<T> &target) {
    std::vector<T> unique;

    for (auto x : source) {
        if (!contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename T>
std::vector<T> functional::intersection(const std::vector<T> &source, const std::vector<T> &target) {
    std::vector<T> unique;

    for (const auto &x : source) {
        if (contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename T>
std::vector<T> functional::slice(const std::vector<T> &vec, const size_t start, const size_t end) {
    auto from = static_cast<int>(std::min(start, vec.size()));
    auto to   = static_cast<int>(std::min(end, vec.size()));

    // cppcheck-suppress internalAstError
    return to > from ? std::vector<T>(vec.begin() + from, vec.begin() + to) : std::vector<T>({});
}

template <typename T>
std::vector<T> functional::slice_first(const std::vector<T> &vec, size_t width) {
    return slice(vec, 0, width);
}

template <typename T>
std::vector<T> functional::slice_last(const std::vector<T> &vec, size_t width) {
    return vec.size() > width ? slice(vec, vec.size() - width, vec.size()) : vec;
}

template <typename T>
std::vector<T> functional::drop_first(const std::vector<T> &vec, size_t width) {
    return slice(vec, width, vec.size());
}

template <typename T>
std::vector<T> functional::drop_last(const std::vector<T> &vec, size_t width) {
    return vec.size() > width ? slice(vec, 0, vec.size() - width) : std::vector<T>();
}

template <typename T>
std::vector<std::vector<T>> functional::aperture(const std::vector<T> &vec, size_t width) {
    std::vector<std::vector<T>> slides;

    if (width == 0 || width > vec.size()) {
        return {};
    }

    for (std::size_t i = 0; i < vec.size() - width + 1; ++i) {
        std::vector<T> slide;

        for (const auto j : range(width)) {
            slide.push_back(vec.at(i + j));
        }

        slides.push_back(slide);
    }

    return slides;
}

template <typename T>
std::vector<T> functional::concat(const std::vector<T> &vec, const T &x) {
    std::vector<T> copy(vec);
    copy.push_back(x);
    return copy;
}

template <typename T>
std::vector<T> functional::concat(const std::vector<T> &vec, const std::vector<T> &x) {
    std::vector<T> copy(vec);
    insert(x, copy);
    return copy;
}

template <typename T>
std::vector<T> functional::flatten(const std::vector<std::vector<T>> &vec) {
    // Proxy concat to pick the correct overload.
    std::function<std::vector<T>(const std::vector<T> &, const std::vector<T> &)> snoc =
        [](const auto &acc, const auto &x) { return concat(acc, x); };

    return functional::fold(snoc, {}, vec);
}

template <typename T>
std::vector<T> functional::from_deque(const std::deque<T> &deque) {
    return std::vector<T>({deque.begin(), deque.end()});
}

#endif