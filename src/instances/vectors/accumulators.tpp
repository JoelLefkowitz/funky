#ifndef ACCUMULATORS_TPP
#define ACCUMULATORS_TPP

#include "../../generics/foldable/fold.tpp"
#include "accumulators.hpp"
#include <functional>
#include <vector>

template <typename T>
T functional::average(const std::vector<T> &vec) {
    std::function<T(T, T)> sum = [](auto acc, auto x) { return acc + x; };

    auto size = static_cast<T>(vec.size());
    return functional::fold(sum, T(), vec) / size;
}

#endif