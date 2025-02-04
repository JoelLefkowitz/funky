#ifndef FUNKY_BOOLEANS_BOOLEANS_HPP
#define FUNKY_BOOLEANS_BOOLEANS_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include <cstddef>
#include <functional>
#include <vector>

namespace funky {
    // all ≔ [ A ] → bool
    template <typename FA>
    bool all(const FA &source);

    // all ≔ (A → bool) → [ A ] → bool
    template <typename FA, typename A = elements<FA>, typename T>
    requires Callable<T, bool(A)>
    bool all(const T &mapper, const FA &source);

    // any ≔ [ A ] → bool
    template <typename FA>
    bool any(const FA &source);

    // any ≔ (A → bool) → [ A ] → bool
    template <typename FA, typename A = elements<FA>, typename T>
    requires Callable<T, bool(A)>
    bool any(const T &mapper, const FA &source);

    // at_least ≔ size_t → [ A ] → bool
    template <typename FA>
    bool at_least(size_t min, const FA &source);

    // at_least ≔ (A → bool) → size_t → [ A ] → bool
    template <typename FA, typename A = elements<FA>, typename T>
    requires Callable<T, bool(A)>
    bool at_least(const T &mapper, size_t min, const FA &source);
}

#endif
