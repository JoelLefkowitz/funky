#ifndef FUNKY_GENERICS_FUNCTOR_PAIR_TPP
#define FUNKY_GENERICS_FUNCTOR_PAIR_TPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include "pair.hpp"
#include <numeric>
#include <utility>
#include <vector>

template <typename FA, typename A>
std::vector<std::pair<A, A>> funky::pair(const FA &source) {
    std::vector<std::pair<A, A>> target;

    if (!source.empty()) {
        for (auto i = source.begin(); (i + 1) != source.end(); ++i) {
            target.push_back({*i, *(i + 1)});
        }
    }

    return target;
}

#endif
