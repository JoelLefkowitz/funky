#ifndef FUNKY_ITERABLES_FOREACH_HPP
#define FUNKY_ITERABLES_FOREACH_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include <cstddef>

namespace funky {
    // foreach: ( A → void ) → [ A ] → void
    template <typename FA, typename A = elements<FA>,  typename T>
    requires Callable<T, void(A)>
    void foreach (const T &effect, const FA &source);

    // foreach: ( A → size_t → void ) → [ A ] → void
    template <typename FA, typename A = elements<FA>,  typename T>
    requires Callable<T, void(A, size_t)>
    void foreach (const T &effect, const FA &source);

    // foreach: ( A → B → void ) → [ A ] → [ B ] → void
    template <typename FA, typename FB, typename A = elements<FA>, typename B = elements<FB>, typename T>
    requires Callable<T, void(A, B)>
    void foreach (const T &effect, const FA &a, const FB &b);

    // foreach: ( A → B → size_t → void ) → [ A ] → [ B ] → void
    template <typename FA, typename FB, typename A = elements<FA>, typename B = elements<FB>, typename T>
    requires Callable<T, void(A, B, size_t)>
    void foreach (const T &effect, const FA &a, const FB &b);
}

#endif
