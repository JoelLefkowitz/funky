#ifndef FUNCTIONAL_GENERICS_SEMIGROUPOID_PIPE_TPP
#define FUNCTIONAL_GENERICS_SEMIGROUPOID_PIPE_TPP

#include "compose.tpp"
#include "pipe.hpp"

template <typename T, typename... F>
auto functional::pipe(const T &x, const F &...fs) {
    return compose(fs...)(x);
}

#endif
