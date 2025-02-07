#ifndef FUNKY_IMPLEMENTATIONS_NUMBERS_LIMITS_TPP
#define FUNKY_IMPLEMENTATIONS_NUMBERS_LIMITS_TPP

#include "numbers.hpp"
#include <algorithm>

template <typename T>
bool funky::between(T lower, T x, T higher) {
    return lower < x && x < higher;
}

template <typename T>
bool funky::contains(T lower, T x, T higher) {
    return lower <= x && x <= higher;
}

template <typename T>
T funky::clamp(T lower, T x, T higher) {
    return std::max(lower, std::min(higher, x));
}

#endif
