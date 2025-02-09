#ifndef FUNKY_CONCRETE_NUMBERS_TPP
#define FUNKY_CONCRETE_NUMBERS_TPP

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
