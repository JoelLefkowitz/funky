#ifndef FUNCTIONAL_GENERICS_SEMIGROUPOID_PIPE_HPP
#define FUNCTIONAL_GENERICS_SEMIGROUPOID_PIPE_HPP

namespace functional {
    template <typename T, typename... F>
    auto pipe(const T &x, const F &...fs);
}

#endif
