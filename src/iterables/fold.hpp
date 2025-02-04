#ifndef FUNKY_ITERABLES_FOLD_HPP
#define FUNKY_ITERABLES_FOLD_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"

namespace funky {
    // fold ≔ (B → A → B) → B → [ A ] → B
    template <typename B, typename FA, typename A = elements<FA>, typename T>
    requires Callable<T, B(B, A)>
    B fold(const T &folder, const B &initial, const FA &source);
}

#endif
