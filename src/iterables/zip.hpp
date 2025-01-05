#ifndef FUNKY_ITERABLES_ZIP_HPP
#define FUNKY_ITERABLES_ZIP_HPP

#include <functional>

namespace funky {
    // (A -> B -> C) -> const F<A> & -> const F<B> & -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(A, B)> &mapper, const F<A> &a, const F<B> &b);

    // (const A & -> B -> C) -> const F<A> & -> const F<B> & -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(const A &, B)> &mapper, const F<A> &a, const F<B> &b);

    // (A -> const B & -> C) -> const F<A> & -> const F<B> & -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(A, const B &)> &mapper, const F<A> &a, const F<B> &b);

    // (const A & -> const B & -> C) -> const F<A> & -> const F<B> & -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(const A &, const B &)> &mapper, const F<A> &a, const F<B> &b);
}

#endif
