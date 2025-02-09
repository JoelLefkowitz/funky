#ifndef FUNKY_GENERICS_MUTABLE_TPP
#define FUNKY_GENERICS_MUTABLE_TPP

#include "../concrete/numbers.tpp"
#include "iterables.tpp"
#include "mutable.hpp"
#include <algorithm>
#include <numeric>

template <typename T>
void funky::insert(const std::vector<T> &source, std::vector<T> &target) {
    target.insert(target.end(), source.begin(), source.end());
}

template <typename A>
void funky::remove(std::vector<A> &vec, A x) {
    auto removed = std::remove(vec.begin(), vec.end(), x);
    vec.erase(removed, vec.end());
}

template <typename A>
void funky::move_to_back(
    const std::function<bool(A)> &filter,
    std::vector<A> &vec
) {
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        if (filter(*i)) {
            auto x = std::move(*i);
            vec.erase(i);
            vec.insert(vec.end(), x);
            break;
        }
    }
}

#endif
