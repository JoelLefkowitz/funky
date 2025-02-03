#ifndef FUNKY_ITERABLES_ZIP_HPP
#define FUNKY_ITERABLES_ZIP_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include <functional>

namespace funky {
    // product: [ A ] → [ B ] → std::vector<std::pair<A, B>>
    template <
        typename FB,
        typename FA,
        typename B = elements<FB>,
        typename A = elements<FA>>
    std::vector<std::pair<A, B>> zip(const FA &a, const FB &b);
}

#endif
