#ifndef FUNKY_GENERICS_SEMIGROUPOID_PIPE_TPP
#define FUNKY_GENERICS_SEMIGROUPOID_PIPE_TPP

#include "compose.tpp"
#include "pipe.hpp"

template <typename T, typename... U>
auto funky::pipe(const T &f, const U &...gs) {
    return compose(gs...)(f);
}

#endif
