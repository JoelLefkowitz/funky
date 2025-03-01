#ifndef FUNKY_CONCRETE_NUMBERS_TPP
#define FUNKY_CONCRETE_NUMBERS_TPP

#include "numbers.hpp"
#include <algorithm>

template <typename A>
bool funky::bounds(A lower, A x, A higher) {
    return lower < x && x < higher;
}

template <typename A>
bool funky::includes(A lower, A x, A higher) {
    return lower <= x && x <= higher;
}

template <typename A>
A funky::clamp(A lower, A x, A higher) {
    return std::max(lower, std::min(higher, x));
}

#endif
