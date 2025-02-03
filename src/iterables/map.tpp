
#ifndef FUNKY_GENERICS_FUNCTOR_MAP_TPP
#define FUNKY_GENERICS_FUNCTOR_MAP_TPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include "map.hpp"
#include <map>
#include <numeric>

template <typename T>
requires funky::Callable<T, char(char)>
std::string funky::map(const T &mapper, const std::string &source) {
    std::string target;
    std::transform(
        source.begin(),
        source.end(),
        std::back_inserter(target),
        mapper
    );
    return target;
}

template <typename C, typename B, typename A, typename T>
requires funky::Callable<T, C(A, B)>
std::vector<C> funky::map(const T &mapper, const std::map<A, B> &source) {
    std::vector<C> target;

    std::transform(
        source.begin(),
        source.end(),
        std::back_inserter(target),
        [&mapper](auto &x) {
            return mapper(x.first, x.second);
        }
    );

    return target;
}

template <typename FB, typename FA, typename B, typename A, typename T>
requires funky::Callable<T, B(A)>
FB funky::map(const T &mapper, const FA &source) {
    FB target;
    std::transform(
        source.begin(),
        source.end(),
        std::back_inserter(target),
        mapper
    );
    return target;
}

#endif
