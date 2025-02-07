#ifndef FUNKY_IMPLEMENTATIONS_BOOLEANS_BOOLEANS_TPP
#define FUNKY_IMPLEMENTATIONS_BOOLEANS_BOOLEANS_TPP

#include "../generics/templates.hpp"
#include "booleans.hpp"
#include <cstddef>
#include <vector>

template <typename FA>
bool funky::all(const FA &source) {
    for (auto x : source) {
        // This is identical to std::all_of without a predicate
        // cppcheck-suppress useStlAlgorithm
        if (!x) {
            return false;
        }
    }

    return true;
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, bool(A)>
bool funky::all(const T &mapper, const FA &source) {
    return std::all_of(source.begin(), source.end(), mapper);
}

template <typename FA>
bool funky::any(const FA &source) {
    for (auto x : source) {
        // This is identical to std::any_of without a predicate
        // cppcheck-suppress useStlAlgorithm
        if (x) {
            return true;
        }
    }

    return false;
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, bool(A)>
bool funky::any(const T &mapper, const FA &source) {
    return std::any_of(source.begin(), source.end(), mapper);
}

template <typename FA>
bool funky::at_least(size_t min, const FA &source) {
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

template <typename FA, typename A, typename T>
requires funky::Callable<T, bool(A)>
bool funky::at_least(const T &mapper, size_t min, const FA &source) {
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

#endif
