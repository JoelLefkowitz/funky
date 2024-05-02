#ifndef FUNCTIONAL_GENERICS_SEMIGROUPOID_COMPOSE_TPP
#define FUNCTIONAL_GENERICS_SEMIGROUPOID_COMPOSE_TPP

#include "compose.hpp"

template <typename F, typename G>
auto functional::compose(const F &f, const G &g) {
    return [f, g](const auto &x) { return g(f(x)); };
}

template <typename F, typename... G>
auto functional::compose(const F &f, const G &...gs) {
    return compose(f, compose(gs...));
}

#endif
