#ifndef FUNKY_GENERICS_SEMIGROUPOID_COMPOSE_TPP
#define FUNKY_GENERICS_SEMIGROUPOID_COMPOSE_TPP

#include "compose.hpp"

template <typename F, typename G>
auto funky::compose(const F &f, const G &g) {
    return [f, g](const auto &x) { return g(f(x)); };
}

template <typename F, typename... G>
auto funky::compose(const F &f, const G &...gs) {
    return compose(f, compose(gs...));
}

#endif
