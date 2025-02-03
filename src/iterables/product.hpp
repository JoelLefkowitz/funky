#ifndef FUNKY_ITERABLES_PRODUCT_HPP
#define FUNKY_ITERABLES_PRODUCT_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"

namespace funky {
    // product: [ A ] → [ B ] → std::vector<std::pair<A, B>>
    template <
        typename FB,
        typename FA,
        typename B = elements<FB>,
        typename A = elements<FA>>
    std::vector<std::pair<A, B>> product(const FA &a, const FB &b);
}

#endif
