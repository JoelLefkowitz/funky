#ifndef FUNKY_ITERABLES_ZIP_HPP
#define FUNKY_ITERABLES_ZIP_HPP

#include <functional>

namespace funky {
    // zip :: (A -> B -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(A, B)> &mapper, const F<A> &a, const F<B> &b);

    // zip :: (const A & -> B -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(const A &, B)> &mapper, const F<A> &a, const F<B> &b);

    // zip :: (A -> const B & -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(A, const B &)> &mapper, const F<A> &a, const F<B> &b);

    // zip :: (const A & -> const B & -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(const A &, const B &)> &mapper, const F<A> &a, const F<B> &b);
}

#endif
