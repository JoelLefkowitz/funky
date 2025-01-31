#ifndef FUNKY_ITERABLES_PAIR_HPP
#define FUNKY_ITERABLES_PAIR_HPP

#include <functional>

namespace funky {
    // pair :: (A -> A -> B) -> F<A> -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(A, A)> &mapper, const F<A> &source);

    // pair :: (const A & -> A -> B) -> F<A> -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(const A &, A)> &mapper, const F<A> &source);

    // pair :: (A -> const A & -> B) -> F<A> -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(A, const A &)> &mapper, const F<A> &source);

    // pair :: (const A & -> const A & -> B) -> F<A> -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(const A &, const A &)> &mapper, const F<A> &source);
}

#endif
