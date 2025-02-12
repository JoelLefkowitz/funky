#ifndef FUNKY_GENERICS_SETS_HPP
#define FUNKY_GENERICS_SETS_HPP

#include "../concepts/callable.hpp"
#include <deque>
#include <map>
#include <string>
#include <vector>

namespace funky {
    // contains ≔ [ A ] → A → bool
    template <typename FA, typename A = Elements<FA>>
    bool contains(const FA &source, const A &x);

    // is_unique ≔ [ A ] → bool
    template <typename FA, typename A = Elements<FA>>
    bool is_unique(const FA &source);

    // unique ≔ [ A ] → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA unique(const FA &source);

    // intersects ≔ [ A ] → [ A ] → bool
    template <typename FA, typename A = Elements<FA>>
    bool intersects(const FA &source, const FA &target);

    // intersection ≔ [ A ] → [ A ] → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA intersection(const FA &source, const FA &target);

    // difference ≔ [ A ] → [ A ] → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA difference(const FA &source, const FA &target);

    // index ≔ [ A ] → A → size_t
    template <typename FA, typename A = Elements<FA>>
    size_t index(const FA &source, const A &x);

    // find ≔ (A → bool) → [ A ] → size_t
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, bool(A)>
    size_t find(const T &condition, const FA &source);

    // min ≔ [ A ] → A → A
    template <typename FA, typename A = Elements<FA>>
    A min(const FA &source, A empty);

    // max ≔ [ A ] → A → A
    template <typename FA, typename A = Elements<FA>>
    A max(const FA &source, A empty);
}

#endif
