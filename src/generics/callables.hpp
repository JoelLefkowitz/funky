#ifndef FUNKY_GENERICS_CALLABLES_HPP
#define FUNKY_GENERICS_CALLABLES_HPP

namespace funky {
    // compose ≔ T → U → auto
    template <typename T, typename U>
    auto compose(const T &f, const U &g);

    // compose ≔ T → U → auto
    template <typename T, typename... U>
    auto compose(const T &f, const U &...gs);

    // pipe ≔ T → U → auto
    template <typename T, typename... U>
    auto pipe(const T &f, const U &...gs);
}

#endif
