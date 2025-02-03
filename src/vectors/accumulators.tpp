#ifndef FUNKY_IMPLEMENTATIONS_VECTORS_ACCUMULATORS_TPP
#define FUNKY_IMPLEMENTATIONS_VECTORS_ACCUMULATORS_TPP

#include "../iterables/fold.tpp"
#include "accumulators.hpp"
#include <vector>

template <typename T>
T funky::average(const std::vector<T> &vec) {
    std::function<T(T, T)> sum = [](auto acc, auto x) { return acc + x; };

    auto size = static_cast<T>(vec.size());
    return funky::fold(sum, T(), vec) / size;
}

#endif
