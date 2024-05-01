#ifndef COMPOSE_HPP
#define COMPOSE_HPP

namespace functional {
    template <typename F, typename G>
    auto compose(const F &f, const G &g);

    template <typename F, typename... G>
    auto compose(const F &f, const G &...gs);
} // namespace functional

#endif
