#ifndef FUNKY_GENERICS_FUNCTOR_PRODUCT_TPP
#define FUNKY_GENERICS_FUNCTOR_PRODUCT_TPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include "product.hpp"
#include <numeric>

template <typename FB, typename FA, typename B, typename A>
std::vector<std::pair<A, B>> funky::product(const FA &a, const FB &b) {
    std::vector<std::pair<A, B>> target;

    for (auto x = a.begin(); x != a.end(); ++x) {
        for (auto y = b.begin(); y != b.end(); ++y) {
            target.push_back({*x, *y});
        }
    }

    return target;
}

#endif
