#ifndef FUNKY_CALLABLES_COMPOSE_HPP
#define FUNKY_CALLABLES_COMPOSE_HPP

namespace funky {
    // compose ≔ T → U → auto
    template <typename T, typename U>
    auto compose(const T &f, const U &g);

    // compose ≔ T → U → auto
    template <typename T, typename... U>
    auto compose(const T &f, const U &...gs);
}

#endif
