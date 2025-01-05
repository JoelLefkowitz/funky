#ifndef FUNKY_BOOLEANS_BOOLEANS_HPP
#define FUNKY_BOOLEANS_BOOLEANS_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace funky {
    // (A -> bool) -> const FA & -> bool
    template <typename FA, typename A>
    bool all(const std::function<bool(A)> &mapper, const FA &source);

    // const FA & -> bool
    template <typename FA>
    bool all(const FA &source);

    // (A -> bool) -> const FA & -> bool
    template <typename FA, typename A>
    bool any(const std::function<bool(A)> &mapper, const FA &source);

    // const FA & -> bool
    template <typename FA>
    bool any(const FA &source);

    // (A -> bool) -> size_t -> const FA & -> bool
    template <typename FA, typename A>
    bool at_least(const std::function<bool(A)> &mapper, size_t min, const FA &source);

    // size_t -> const FA & -> bool
    template <typename FA>
    bool at_least(size_t min, const FA &source);
}

#endif
