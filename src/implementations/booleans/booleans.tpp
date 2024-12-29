#ifndef FUNKY_IMPLEMENTATIONS_BOOLEANS_BOOLEANS_TPP
#define FUNKY_IMPLEMENTATIONS_BOOLEANS_BOOLEANS_TPP

#include "booleans.hpp"
#include <cstddef>
#include <functional>
#include <vector>

template <typename FA, typename A>
bool funky::all(const std::function<bool(A)> &mapper, const FA &source) {
    return std::all_of(source.begin(), source.end(), mapper);
}

template <typename F>
bool funky::all(const F &source) {
    for (auto x : source) {
        // This is identical to std::all_of without a predicate
        // cppcheck-suppress useStlAlgorithm
        if (!x) {
            return false;
        }
    }

    return true;
}

template <typename FA, typename A>
bool funky::any(const std::function<bool(A)> &mapper, const FA &source) {
    return std::any_of(source.begin(), source.end(), mapper);
}

template <typename F>
bool funky::any(const F &source) {
    for (auto x : source) {
        // This is identical to std::any_of without a predicate
        // cppcheck-suppress useStlAlgorithm
        if (x) {
            return true;
        }
    }

    return false;
}

template <typename FA, typename A>
bool funky::at_least(const std::function<bool(A)> &mapper, size_t min, const FA &source) {
    if (min == 0) {
        return true;
    }

    for (auto x : source) {
        if (mapper(x)) {
            --min;
        }

        if (min == 0) {
            return true;
        }
    }

    return false;
}

template <typename F>
bool funky::at_least(size_t min, const F &source) {
    if (min == 0) {
        return true;
    }

    for (auto x : source) {
        if (x) {
            --min;
        }

        if (min == 0) {
            return true;
        }
    }

    return false;
}

#endif
