#ifndef FUNKY_GENERICS_FUNCTOR_ZIP_TPP
#define FUNKY_GENERICS_FUNCTOR_ZIP_TPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include "zip.hpp"
#include <numeric>

template <typename FB, typename FA, typename B, typename A>
std::vector<std::pair<A, B>> funky::zip(const FA &a, const FB &b) {
    std::vector<std::pair<A, B>> target;

    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        target.push_back({*x, *y});
    }

    return target;
}

#endif
