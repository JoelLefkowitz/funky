#ifndef FUNKY_GENERICS_SEMIGROUPOID_COMPOSE_TPP
#define FUNKY_GENERICS_SEMIGROUPOID_COMPOSE_TPP

#include "callables.hpp"

template <typename T, typename U>
auto funky::compose(const T &f, const U &g) {
    return [f, g](const auto &x) {
        return g(f(x));
    };
}

template <typename T, typename... U>
auto funky::compose(const T &f, const U &...gs) {
    return compose(f, compose(gs...));
}

template <typename T, typename... U>
auto funky::pipe(const T &f, const U &...gs) {
    return compose(gs...)(f);
}

#endif
