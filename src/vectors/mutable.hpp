#ifndef FUNKY_VECTORS_MUTABLE_HPP
#define FUNKY_VECTORS_MUTABLE_HPP

#include <cstddef>
#include <vector>

namespace funky {
    template <typename T>
    void insert(const std::vector<T> &source, std::vector<T> &target);

    template <typename T>
    void erase(std::vector<T> &vec, T x);

    template <typename T>
    void move_to_back(const std::function<bool(T)> &filter, std::vector<T> &vec);
}

#endif
