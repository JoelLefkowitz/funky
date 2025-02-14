#ifndef FUNKY_GENERICS_PAIRS_HPP
#define FUNKY_GENERICS_PAIRS_HPP

#include "../concepts/aliases.hpp"
#include "../concepts/callable.hpp"
#include <map>
#include <utility>
#include <vector>

namespace funky {
    // zip ≔ [ A ] → [ B ] → std::vector<std::pair<A, B>>
    template <typename FB, typename FA, typename B = Elements<FB>, typename A = Elements<FA>>
    std::vector<std::pair<A, B>> zip(const FA &a, const FB &b);

    // product ≔ [ A ] → [ B ] → std::vector<std::pair<A, B>>
    template <typename FB, typename FA, typename B = Elements<FB>, typename A = Elements<FA>>
    std::vector<std::pair<A, B>> product(const FA &a, const FB &b);

    // pairs ≔ std::map<A, B> → std::vector<std::pair<A, B>>
    template <typename A, typename B>
    std::vector<std::pair<A, B>> pairs(const std::map<A, B> &source);
}

#endif
