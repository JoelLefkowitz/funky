#ifndef FUNKY_GENERICS_PAIRS_TPP
#define FUNKY_GENERICS_PAIRS_TPP

#include "../concepts/callable.hpp"
#include "pairs.hpp"
#include <numeric>
#include <utility>
#include <vector>

template <typename FB, typename FA, typename B, typename A>
std::vector<std::pair<A, B>> funky::zip(const FA &a, const FB &b) {
    std::vector<std::pair<A, B>> target;

    auto x = a.begin();

    for (const auto &y : b) {
        target.push_back({*x, y});
        x++;
    }

    return target;
}

template <typename FB, typename FA, typename B, typename A>
std::vector<std::pair<A, B>> funky::product(const FA &a, const FB &b) {
    std::vector<std::pair<A, B>> target;

    for (const auto &x : a) {
        for (const auto &y : b) {
            // This is identical to std::transform without creating extra
            // closures
            // cppcheck-suppress useStlAlgorithm
            target.push_back({x, y});
        }
    }

    return target;
}

template <typename A, typename B>
std::vector<std::pair<A, B>> funky::pairs(const std::map<A, B> &source) {
    std::vector<std::pair<A, B>> target;
    std::copy(source.begin(), source.end(), std::back_inserter(target));
    return target;
}

#endif
