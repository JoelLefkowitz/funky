#ifndef FUNKY_GENERICS_MUTABLE_TPP
#define FUNKY_GENERICS_MUTABLE_TPP

#include "../concrete/numbers.tpp"
#include "iterables.tpp"
#include "mutable.hpp"
#include <algorithm>
#include <numeric>

template <typename FA, typename A>
void funky::insert(const FA &source, FA &target) {
    target.insert(target.end(), source.begin(), source.end());
}

template <typename FA, typename A>
void funky::remove(FA &source, const A &x) {
    auto removed = std::remove(source.begin(), source.end(), x);
    source.erase(removed, source.end());
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, bool(A)>
void funky::partition(const T &filter, FA &source) {
    for (auto i = source.begin(); i != source.end(); ++i) {
        if (filter(*i)) {
            auto x = std::move(*i);
            source.erase(i);
            source.insert(source.end(), x);
            break;
        }
    }
}

#endif
