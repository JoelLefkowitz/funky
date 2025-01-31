#ifndef FUNKY_ITERABLES_FOLD_HPP
#define FUNKY_ITERABLES_FOLD_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"

namespace funky {
    // fold :: ( B -> A -> B ) -> B -> [ A ] -> B
    template <typename B, typename T, typename FA, typename A = elements<FA>>
    requires Callable<T, B(B, A)>
    B fold(const T &folder, const B &initial, const FA &source);
}

#endif
