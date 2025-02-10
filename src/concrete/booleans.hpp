#ifndef FUNKY_CONCRETE_BOOLEANS_HPP
#define FUNKY_CONCRETE_BOOLEANS_HPP

#include "../concepts/aliases.hpp"
#include "../concepts/callable.hpp"
#include <cstddef>
#include <functional>
#include <vector>

namespace funky {
    // all ≔ [ A ] → bool
    template <typename FA>
    bool all(const FA &source);

    // all ≔ (A → bool) → [ A ] → bool
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, bool(A)>
    bool all(const T &predicate, const FA &source);

    // any ≔ [ A ] → bool
    template <typename FA>
    bool any(const FA &source);

    // any ≔ (A → bool) → [ A ] → bool
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, bool(A)>
    bool any(const T &predicate, const FA &source);

    // at_least ≔ size_t → [ A ] → bool
    template <typename FA>
    bool at_least(size_t min, const FA &source);

    // at_least ≔ (A → bool) → size_t → [ A ] → bool
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, bool(A)>
    bool at_least(const T &predicate, size_t min, const FA &source);
}

#endif
