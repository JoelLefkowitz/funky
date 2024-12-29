#ifndef FUNKY_GENERICS_FUNCTOR_PAIR_HPP
#define FUNKY_GENERICS_FUNCTOR_PAIR_HPP

#include <functional>

namespace funky {
    // (A -> A -> B) -> const F<A> & -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(A, A)> &mapper, const F<A> &source);

    // (const A & -> A -> B) -> const F<A> & -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(const A &, A)> &mapper, const F<A> &source);

    // (A -> const A & -> B) -> const F<A> & -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(A, const A &)> &mapper, const F<A> &source);

    // (const A & -> const A & -> B) -> const F<A> & -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(const A &, const A &)> &mapper, const F<A> &source);
} // namespace functional

#endif
