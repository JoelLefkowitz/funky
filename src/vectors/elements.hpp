#ifndef FUNKY_VECTORS_ELEMENTS_HPP
#define FUNKY_VECTORS_ELEMENTS_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace funky {
    // min ≔ std::vector<T> → T
    template <typename T>
    T min(const std::vector<T> &vec);

    // max ≔ std::vector<T> → T
    template <typename T>
    T max(const std::vector<T> &vec);

    // index ≔ std::vector<T> → T → size_t
    template <typename T>
    size_t index(const std::vector<T> &vec, const T &x);

    // index ≔ (const T & → bool) → std::vector<T> → size_t
    template <typename T>
    size_t index(
        std::function<bool(const T &)> condition,
        const std::vector<T> &vec
    );

    // contains ≔ std::vector<T> → T → bool
    template <typename T>
    bool contains(const std::vector<T> &vec, const T &x);

    // repeats ≔ std::vector<T> → bool
    template <typename T>
    bool repeats(const std::vector<T> &vec);

    // overlaps ≔ std::vector<T> → std::vector<T> → bool
    template <typename T>
    bool overlaps(const std::vector<T> &source, const std::vector<T> &target);
}

#endif
