#ifndef FUNCTIONAL_GENERICS_FUNCTOR_FOREACH_HPP
#define FUNCTIONAL_GENERICS_FUNCTOR_FOREACH_HPP

#include <cstddef>
#include <functional>

namespace functional {
    /**
     * forall F A. (A -> Unit) -> FA -> Unit
     */
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(A)> &effect, const FA &source);

    /**
     * forall F A. (A -> size_t -> Unit) -> FA -> Unit
     */
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(A, size_t)> &effect, const FA &source);

    /**
     * forall F A. (const A& -> Unit) -> FA -> Unit
     */
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(const A &)> &effect, const FA &source);

    /**
     * forall F A. (const A& -> size_t -> Unit) -> FA -> Unit
     */
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(const A &, size_t)> &effect, const FA &source);

    /**
     * forall F A B. (A -> B -> Unit) -> FA -> FB -> Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, B)> &effect, const FA &a, const FB &b);

    /**
     * forall F A B. (A -> B -> size_t -> Unit) -> FA -> FB -> Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, B, size_t)> &effect, const FA &a, const FB &b);

    /**
     * forall F A B. (const A& -> B -> Unit) -> FA -> FB -> Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, B)> &effect, const FA &a, const FB &b);

    /**
     * forall F A B. (const A& -> B -> size_t -> Unit) -> FA -> FB -> Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, B, size_t)> &effect, const FA &a, const FB &b);

    /**
     * forall F A B. (A -> const B& -> Unit) -> FA -> FB -> Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, const B &)> &effect, const FA &a, const FB &b);

    /**
     * forall F A B. (A -> const B& -> size_t -> Unit) -> FA -> FB -> Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, const B &, size_t)> &effect, const FA &a, const FB &b);

    /**
     * forall F A B. (const A& -> const B& -> Unit) -> FA -> FB -> Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, const B &)> &effect, const FA &a, const FB &b);

    /**
     * forall F A B. (const A& -> const B& -> size_t -> Unit) -> FA -> FB ->
     * Unit
     */
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, const B &, size_t)> &effect, const FA &a, const FB &b);
} // namespace functional

#endif
