#ifndef FUNKY_CONCRETE_BOOLEANS_TPP
#define FUNKY_CONCRETE_BOOLEANS_TPP

#include "../concepts/callable.hpp"
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
bool funky::all(const T &predicate, const FA &source) {
    return std::all_of(source.begin(), source.end(), predicate);
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
bool funky::any(const T &predicate, const FA &source) {
    return std::any_of(source.begin(), source.end(), predicate);
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
bool funky::at_least(const T &predicate, size_t min, const FA &source) {
    if (min == 0) {
        return true;
    }

    for (auto x : source) {
        if (predicate(x)) {
            --min;
        }

        if (min == 0) {
            return true;
        }
    }

    return false;
}

#endif
