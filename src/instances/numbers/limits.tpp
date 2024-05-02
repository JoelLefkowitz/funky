#ifndef FUNCTIONAL_INSTANCES_NUMBERS_LIMITS_TPP
#define FUNCTIONAL_INSTANCES_NUMBERS_LIMITS_TPP

#include "limits.hpp"
#include <algorithm>

template <typename T>
bool functional::between(T lower, T x, T higher) {
    return lower < x && x < higher;
}

template <typename T>
bool functional::contains(T lower, T x, T higher) {
    return lower <= x && x <= higher;
}

template <typename T>
T functional::clamp(T lower, T x, T higher) {
    return std::max(lower, std::min(higher, x));
}

#endif
