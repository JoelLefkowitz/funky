#ifndef FUNKY_GENERICS_SEMIGROUPOID_PIPE_HPP
#define FUNKY_GENERICS_SEMIGROUPOID_PIPE_HPP

namespace funky {
    template <typename T, typename... F>
    auto pipe(const T &x, const F &...fs);
}

#endif
