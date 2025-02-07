#ifndef FUNKY_VECTORS_RANGES_HPP
#define FUNKY_VECTORS_RANGES_HPP

#include "../generics/templates.hpp"
#include <cstddef>
#include <utility>
#include <vector>

namespace funky {
    // range ≔ size_t → std::vector<size_t>
    std::vector<size_t> range(size_t limit);

    // range ≔ T → T → T → std::vector<T>
    template <typename T>
    std::vector<T> range(T start, T stop, T step = 1);

    // linspace ≔ T → T → size_t → std::vector<T>
    template <typename T>
    std::vector<T> linspace(T start, T stop, size_t count);

    // enumerate ≔ std::vector<T> → std::vector<Indexed<T>>
    template <typename T>
    std::vector<Indexed<T>> enumerate(const std::vector<T> &vec);
}

#endif
