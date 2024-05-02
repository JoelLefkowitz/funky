#ifndef FUNCTIONAL_INSTANCES_VECTORS_ELEMENTS_HPP
#define FUNCTIONAL_INSTANCES_VECTORS_ELEMENTS_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace functional {
    template <typename T>
    T min(const std::vector<T> &vec);

    template <typename T>
    T max(const std::vector<T> &vec);

    template <typename T>
    size_t index(const std::vector<T> &vec, const T &x);

    template <typename T>
    size_t index(std::function<bool(const T &)> condition, const std::vector<T> &vec);

    template <typename T>
    bool contains(const std::vector<T> &vec, const T &x);

    template <typename T>
    bool repeats(const std::vector<T> &vec);

    template <typename T>
    bool overlaps(const std::vector<T> &source, const std::vector<T> &target);
} // namespace functional

#endif
