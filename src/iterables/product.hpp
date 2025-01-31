#ifndef FUNKY_ITERABLES_PRODUCT_HPP
#define FUNKY_ITERABLES_PRODUCT_HPP

#include <functional>

namespace funky {
    // product :: (A -> B -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> product(const std::function<C(A, B)> &mapper, const F<A> &a, const F<B> &b);

    // product :: (const A & -> B -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> product(const std::function<C(const A &, B)> &mapper, const F<A> &a, const F<B> &b);

    // product :: (A -> const B & -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> product(const std::function<C(A, const B &)> &mapper, const F<A> &a, const F<B> &b);

    // product :: (const A & -> const B & -> C) -> F<A> -> F<B> -> F<C>
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> product(const std::function<C(const A &, const B &)> &mapper, const F<A> &a, const F<B> &b);
}

#endif
