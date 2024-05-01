#ifndef ZIP_HPP
#define ZIP_HPP

#include <functional>

namespace functional {
    /**
     * forall F A B C. (A -> B -> C) -> FA -> FB -> FC
     */
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(A, B)> &mapper, const F<A> &a, const F<B> &b);

    /**
     * forall F A B C. (const A& -> B -> C) -> FA -> FB -> FC
     */
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(const A &, B)> &mapper, const F<A> &a, const F<B> &b);

    /**
     * forall F A B C. (A -> const B& -> C) -> FA -> FB -> FC
     */
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(A, const B &)> &mapper, const F<A> &a, const F<B> &b);

    /**
     * forall F A B C. (const A& -> const B& -> C) -> FA -> FB -> FC
     */
    template <template <typename...> typename F, typename A, typename B, typename C>
    F<C> zip(const std::function<C(const A &, const B &)> &mapper, const F<A> &a, const F<B> &b);
} // namespace functional

#endif
