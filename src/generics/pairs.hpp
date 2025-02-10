#ifndef FUNKY_GENERICS_PAIRS_HPP
#define FUNKY_GENERICS_PAIRS_HPP

#include "../concepts/aliases.hpp"
#include "../concepts/callable.hpp"
#include <utility>

namespace funky {
    // pairs ≔ [ A ] → std::vector<std::pair<A,A>>
    template <typename FA, typename A = Elements<FA>>
    std::vector<std::pair<A, A>> pairs(const FA &source);

    // product ≔ [ A ] → [ B ] → std::vector<std::pair<A, B>>
    template <
        typename FB,
        typename FA,
        typename B = Elements<FB>,
        typename A = Elements<FA>>
    std::vector<std::pair<A, B>> product(const FA &a, const FB &b);

    // zip ≔ [ A ] → [ B ] → std::vector<std::pair<A, B>>
    template <
        typename FB,
        typename FA,
        typename B = Elements<FB>,
        typename A = Elements<FA>>
    std::vector<std::pair<A, B>> zip(const FA &a, const FB &b);
}

#endif
