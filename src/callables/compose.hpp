#ifndef FUNKY_CALLABLES_COMPOSE_HPP
#define FUNKY_CALLABLES_COMPOSE_HPP

namespace funky {
    // const T & -> const U & -> auto
    template <typename T, typename U>
    auto compose(const T &f, const U &g);

    // const T & -> const U & -> auto
    template <typename T, typename... U>
    auto compose(const T &f, const U &...gs);
}

#endif
