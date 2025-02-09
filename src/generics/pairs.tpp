#ifndef FUNKY_GENERICS_PAIRS_TPP
#define FUNKY_GENERICS_PAIRS_TPP

#include "pairs.hpp"
#include "concepts.hpp"
#include <numeric>
#include <utility>
#include <vector>

template <typename FA, typename A>
std::vector<std::pair<A, A>> funky::pairs(const FA &source) {
    std::vector<std::pair<A, A>> target;

    if (!source.empty()) {
        for (auto i = source.begin(); (i + 1) != source.end(); ++i) {
            target.push_back({*i, *(i + 1)});
        }
    }

    return target;
}

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
