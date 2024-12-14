#ifndef FUNCTIONAL_IMPLEMENTATIONS_VECTORS_IMMUTABLE_HPP
#define FUNCTIONAL_IMPLEMENTATIONS_VECTORS_IMMUTABLE_HPP

#include <cstddef>
#include <deque>
#include <vector>

namespace functional {
    template <typename T>
    std::vector<T> unique(const std::vector<T> &vec);

    template <typename T>
    std::vector<T> reverse(const std::vector<T> &vec);

    template <typename T>
    std::vector<T> difference(const std::vector<T> &source, const std::vector<T> &target);

    template <typename T>
    std::vector<T> intersection(const std::vector<T> &source, const std::vector<T> &target);

    template <typename T>
    std::vector<T> slice(const std::vector<T> &vec, const size_t start, const size_t end);

    template <typename T>
    std::vector<T> slice_first(const std::vector<T> &vec, size_t width);

    template <typename T>
    std::vector<T> slice_last(const std::vector<T> &vec, size_t width);

    template <typename T>
    std::vector<T> drop_first(const std::vector<T> &vec, size_t width);

    template <typename T>
    std::vector<T> drop_last(const std::vector<T> &vec, size_t width);

    template <typename T>
    std::vector<std::vector<T>> aperture(const std::vector<T> &vec, size_t width);

    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const T &x);

    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const std::vector<T> &x);

    template <typename T>
    std::vector<T> flatten(const std::vector<std::vector<T>> &vec);

    template <typename T>
    std::vector<T> from_deque(const std::deque<T> &deque);
} // namespace functional

#endif
