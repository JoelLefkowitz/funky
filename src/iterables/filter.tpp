#ifndef FUNKY_GENERICS_FUNCTOR_FILTER_TPP
#define FUNKY_GENERICS_FUNCTOR_FILTER_TPP

#include "filter.hpp"
#include <algorithm>
#include <functional>

template <typename FA, typename A>
FA funky::filter(const std::function<bool(A)> &condition, const FA &source) {
    FA filtered;

    auto inserter = std::back_inserter(filtered);

    for (auto x : source) {
        if (condition(x)) {
            *inserter = x;
        }
    }

    return filtered;
}

template <typename FA, typename A>
FA funky::filter(const std::function<bool(const A &)> &condition, const FA &source) {
    FA filtered;

    auto inserter = std::back_inserter(filtered);

    for (const auto &x : source) {
        if (condition(x)) {
            *inserter = x;
        }
    }

    return filtered;
}

#endif
