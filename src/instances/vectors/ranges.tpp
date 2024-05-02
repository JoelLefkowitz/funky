#ifndef FUNCTIONAL_INSTANCES_VECTORS_RANGES_TPP
#define FUNCTIONAL_INSTANCES_VECTORS_RANGES_TPP

#include "ranges.hpp"
#include <numeric>
#include <utility>

template <typename T>
std::vector<T> functional::range(T start, T stop, T step) {
    std::vector<T> sequence;

    auto width = static_cast<double>(stop - start);
    auto steps = static_cast<size_t>(std::ceil(width / step));

    for (auto i : range(steps)) {
        auto index = static_cast<T>(i);
        sequence.push_back(start + step * index);
    }

    return sequence;
}

template <typename T>
std::vector<T> functional::linspace(T start, T stop, size_t count) {
    if (count == 0) {
        return {};
    }

    if (count == 1) {
        return {start};
    }

    std::vector<T> sequence;

    auto width = static_cast<double>(stop - start);

    for (auto i : range(count)) {
        auto index = static_cast<T>(i);
        sequence.push_back(start + index * width / (count - 1));
    }

    return sequence;
}

template <typename T>
std::vector<std::pair<size_t, T>> functional::enumerate(const std::vector<T> &vec) {
    std::vector<std::pair<size_t, T>> pairs;

    for (std::size_t i = 0; i < vec.size(); ++i) {
        pairs.push_back({i, vec[i]});
    }

    return pairs;
}

#endif
