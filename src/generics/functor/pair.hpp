#ifndef PAIR_HPP
#define PAIR_HPP

#include <functional>

namespace functional {
    /**
     * forall F A B. (A -> A -> B) -> FA -> FB
     */
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(A, A)> &mapper, const F<A> &source);

    /**
     * forall F A B. (const A& -> A -> B) -> FA -> FB
     */
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(const A &, A)> &mapper, const F<A> &source);

    /**
     * forall F A B. (A -> const A& -> B) -> FA -> FB
     */
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(A, const A &)> &mapper, const F<A> &source);

    /**
     * forall F A B. (const A& -> const A& -> B) -> FA -> FB
     */
    template <template <typename...> typename F, typename A, typename B>
    F<B> pair(const std::function<B(const A &, const A &)> &mapper, const F<A> &source);
} // namespace functional

#endif
