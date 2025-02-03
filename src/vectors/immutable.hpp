#ifndef FUNKY_VECTORS_IMMUTABLE_HPP
#define FUNKY_VECTORS_IMMUTABLE_HPP

#include <cstddef>
#include <deque>
#include <vector>

namespace funky {
    // unique: std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> unique(const std::vector<T> &vec);

    // reverse: std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> reverse(const std::vector<T> &vec);

    // difference: std::vector<T> → std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> difference(const std::vector<T> &source, const std::vector<T> &target);

    // intersection: std::vector<T> → std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> intersection(const std::vector<T> &source, const std::vector<T> &target);

    // slice: std::vector<T> → size_t → size_t → std::vector<T>
    template <typename T>
    std::vector<T> slice(const std::vector<T> &vec, const size_t start, const size_t end);

    // slice_first: std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> slice_first(const std::vector<T> &vec, size_t width);

    // slice_last: std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> slice_last(const std::vector<T> &vec, size_t width);

    // drop_first: std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> drop_first(const std::vector<T> &vec, size_t width);

    // drop_last: std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> drop_last(const std::vector<T> &vec, size_t width);

    // aperture: std::vector<T> → size_t → std::vector<std::vector<T>>
    template <typename T>
    std::vector<std::vector<T>> aperture(const std::vector<T> &vec, size_t width);

    // concat: std::vector<T> → T → std::vector<T>
    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const T &x);

    // concat: std::vector<T> → std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const std::vector<T> &x);

    // flatten: std::vector<std::vector<T>> → std::vector<T>
    template <typename T>
    std::vector<T> flatten(const std::vector<std::vector<T>> &vec);

    // from_deque: std::deque<T> → std::vector<T>
    template <typename T>
    std::vector<T> from_deque(const std::deque<T> &deque);
}

#endif
