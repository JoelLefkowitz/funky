#ifndef FUNKY_CONCRETE_VECTORS_TPP
#define FUNKY_CONCRETE_VECTORS_TPP

#include "vectors.hpp"
#include <deque>
#include <numeric>
#include <utility>

template <typename A>
std::vector<A> funky::range(A start, A stop, A step) {
    std::vector<A> sequence;

    auto width = static_cast<double>(stop - start);
    auto steps = static_cast<size_t>(std::ceil(width / step));

    for (auto i : range(steps)) {
        auto index = static_cast<A>(i);
        sequence.push_back(start + step * index);
    }

    return sequence;
}

template <typename A>
std::vector<A> funky::linspace(A start, A stop, size_t count) {
    if (count == 0) {
        return {};
    }

    if (count == 1) {
        return {start};
    }

    std::vector<A> sequence;

    auto width = static_cast<double>(stop - start);

    for (auto i : range(count)) {
        auto index = static_cast<A>(i);
        sequence.push_back(start + index * width / (count - 1));
    }

    return sequence;
}

template <typename A>
std::vector<std::pair<size_t, A>> funky::enumerate(const std::vector<A> &vec) {
    std::vector<std::pair<size_t, A>> pairs;

    for (std::size_t i = 0; i < vec.size(); ++i) {
        pairs.push_back({i, vec[i]});
    }

    return pairs;
}

template <typename A>
std::vector<A> funky::from_deque(const std::deque<A> &deque) {
    return std::vector<A>({deque.begin(), deque.end()});
}

#endif
