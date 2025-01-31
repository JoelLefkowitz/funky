#ifndef FUNKY_GENERICS_FUNCTOR_FOREACH_TPP
#define FUNKY_GENERICS_FUNCTOR_FOREACH_TPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include "foreach.hpp"
#include <algorithm>
#include <cstddef>

template <typename T, typename FA, typename A>
requires Callable<T, void(A)>
void funky::foreach (const T &effect, const FA &source) {
    std::for_each(source.begin(), source.end(), effect);
}

template <typename T, typename FA, typename A>
requires Callable<T, void(A, size_t)>
void funky::foreach (const T &effect, const FA &source) {
    for (auto x = source.begin(); x != source.end(); ++x) {
        auto index = static_cast<size_t>(x - source.begin());
        effect(*x, index);
    }
}

template <typename T, typename FA, typename FB, typename A, typename B>
requires Callable<T, void(A, B)>
void funky::foreach (const T &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        effect(*x, *y);
    }
}

template <typename T, typename FA, typename FB, typename A, typename B>
requires Callable<T, void(A, B, size_t)>
void funky::foreach (const T &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        auto index = static_cast<size_t>(x - a.begin());
        effect(*x, *y, index);
    }
}

#endif
