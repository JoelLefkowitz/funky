#ifndef FUNKY_ITERABLES_FILTER_HPP
#define FUNKY_ITERABLES_FILTER_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"

namespace funky {
    // filter :: ( A -> bool ) -> [ A ] -> [ A ]
    template <typename T, typename FA, typename A = elements<FA>>
    requires Callable<T, bool(A)>
    FA filter(const T &condition, const FA &source);
}

#endif
