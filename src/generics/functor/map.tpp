#ifndef MAP_TPP
#define MAP_TPP

#include "map.hpp"
#include <functional>
#include <map>
#include <numeric>

template <template <typename...> typename F, typename A, typename B>
F<B> functional::map(const std::function<B(A)> &mapper, const F<A> &source) {
    F<B> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target), mapper);
    return target;
}

template <template <typename...> typename F, typename A, typename B>
F<B> functional::map(const std::function<B(const A &)> &mapper, const F<A> &source) {
    F<B> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target), mapper);
    return target;
}

template <typename A, typename B, typename C>
std::vector<C> functional::map(const std::function<C(const A &, const B &)> &mapper, const std::map<A, B> &source) {
    std::vector<C> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target), [&mapper](auto &x) {
        return mapper(x.first, x.second);
    });
    return target;
}

#endif