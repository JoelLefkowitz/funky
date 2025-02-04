#ifndef FUNKY_ITERABLES_FILTER_HPP
#define FUNKY_ITERABLES_FILTER_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"

namespace funky {
    // filter ≔ (A → bool) → [ A ] → [ A ]
    template <typename FA, typename A = elements<FA>, typename T>
    requires Callable<T, bool(A)>
    FA filter(const T &condition, const FA &source);
}

#endif
