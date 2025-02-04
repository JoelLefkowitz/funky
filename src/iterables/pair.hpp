#ifndef FUNKY_ITERABLES_PAIR_HPP
#define FUNKY_ITERABLES_PAIR_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include <utility>

namespace funky {
    // pair ≔ [ A ] → std::vector<std::pair<A,A>>
    template <typename FA, typename A = elements<FA>>
    std::vector<std::pair<A, A>> pair(const FA &source);
}

#endif
