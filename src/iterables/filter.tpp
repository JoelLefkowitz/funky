#ifndef FUNKY_GENERICS_FUNCTOR_FILTER_TPP
#define FUNKY_GENERICS_FUNCTOR_FILTER_TPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include "filter.hpp"

template <typename T, typename FA, typename A>
requires Callable<T, bool(A)>
FA funky::filter(const T &condition, const FA &source) {
    FA filtered;

    auto inserter = std::back_inserter(filtered);

    for (auto x : source) {
        if (condition(x)) {
            *inserter = x;
        }
    }

    return filtered;
}

#endif
