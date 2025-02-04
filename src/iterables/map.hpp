#ifndef FUNKY_ITERABLES_MAP_HPP
#define FUNKY_ITERABLES_MAP_HPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include <map>
#include <string>
#include <vector>

namespace funky {
    // map ≔ (char → char) → std::string → std::string
    template <typename T>
    requires Callable<T, char(char)>
    std::string map(const T &mapper, const std::string &source);

    // map ≔ (A → B → C) → std::map<A, B> → std::vector<C>
    template <typename C, typename B, typename A, typename T>
    requires Callable<T, C(A, B)>
    std::vector<C> map(const T &mapper, const std::map<A, B> &source);

    // map ≔ (A → B) → [ A ] → [ B ]
    template <
        typename FB,
        typename FA,
        typename B = elements<FB>,
        typename A = elements<FA>,
        typename T>
    requires Callable<T, B(A)>
    FB map(const T &mapper, const FA &source);
}

#endif
