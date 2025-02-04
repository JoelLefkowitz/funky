#ifndef FUNKY_VECTORS_MUTABLE_HPP
#define FUNKY_VECTORS_MUTABLE_HPP

#include <cstddef>
#include <vector>

namespace funky {
    // insert ≔ std::vector<T> → std::vector<T> → void
    template <typename T>
    void insert(const std::vector<T> &source, std::vector<T> &target);

    // erase ≔ std::vector<T> → T → void
    template <typename T>
    void erase(std::vector<T> &vec, T x);

    // move_to_back ≔ (T → bool) → std::vector<T> → void
    template <typename T>
    void move_to_back(
        const std::function<bool(T)> &filter,
        std::vector<T> &vec
    );
}

#endif
