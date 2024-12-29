#ifndef FUNKY_IMPLEMENTATIONS_VECTORS_RANGES_HPP
#define FUNKY_IMPLEMENTATIONS_VECTORS_RANGES_HPP

#include <cstddef>
#include <utility>
#include <vector>

namespace funky {
    std::vector<size_t> range(size_t limit);

    template <typename T>
    std::vector<T> range(T start, T stop, T step = 1);

    template <typename T>
    std::vector<T> linspace(T start, T stop, size_t count);

    template <typename T>
    std::vector<std::pair<size_t, T>> enumerate(const std::vector<T> &vec);
} // namespace functional

#endif
