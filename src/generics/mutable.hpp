#ifndef FUNKY_GENERICS_MUTABLE_HPP
#define FUNKY_GENERICS_MUTABLE_HPP

#include <cstddef>
#include <vector>

namespace funky {
    // insert ≔ [ A ] → [ A ] → void
    template <typename FA, typename A = Elements<FA>>
    void insert(const FA &source, FA &target);

    // remove ≔ [ A ] → A → void
    template <typename FA, typename A = Elements<FA>>
    void remove(FA &source, const A &x);

    // partition ≔ (A → bool) → [ A ] → void
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, bool(A)>
    void partition(const T &filter, FA &source);
}

#endif
