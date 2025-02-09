#ifndef FUNKY_GENERICS_SETS_TPP
#define FUNKY_GENERICS_SETS_TPP

#include "../concrete/numbers.hpp"
#include "../concrete/vectors.tpp"
#include "sets.hpp"
#include "mutable.tpp"
#include "concepts.hpp"
#include <algorithm>
#include <deque>
#include <map>
#include <numeric>

template <typename A>
A funky::min(const std::vector<A> &vec, A empty) {
    return vec.empty() ? empty : *std::min_element(vec.begin(), vec.end());
}

template <typename A>
A funky::max(const std::vector<A> &vec, A empty) {
    return vec.empty() ? empty : *std::max_element(vec.begin(), vec.end());
}

template <typename A>
size_t funky::index(const std::vector<A> &vec, const A &x) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) == x) {
            return i;
        }
    }

    return 0;
}

template <typename T>
size_t funky::index(
    std::function<bool(const T &)> condition,
    const std::vector<T> &vec
) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (condition(vec.at(i))) {
            return i;
        }
    }

    return 0;
}

template <typename A>
bool funky::contains(const std::vector<A> &vec, const A &x) {
    return std::find(vec.begin(), vec.end(), x) != vec.end();
}

template <typename A>
bool funky::repeats(const std::vector<A> &vec) {
    return vec.size() > unique(vec).size();
}

template <typename A>
bool funky::overlaps(
    const std::vector<A> &source,
    const std::vector<A> &target
) {
    return !intersection(source, target).empty();
}

template <typename A>
std::vector<A> funky::unique(const std::vector<A> &vec) {
    std::vector<A> unique;

    for (auto x : vec) {
        if (!contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename A>
std::vector<A> funky::difference(
    const std::vector<A> &source,
    const std::vector<A> &target
) {
    std::vector<A> unique;

    for (auto x : source) {
        if (!contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename A>
std::vector<A> funky::intersection(
    const std::vector<A> &source,
    const std::vector<A> &target
) {
    std::vector<A> unique;

    for (const auto &x : source) {
        if (contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

#endif
