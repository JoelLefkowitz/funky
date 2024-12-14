#ifndef FUNCTIONAL_GENERICS_FUNCTOR_FOREACH_HPP
#define FUNCTIONAL_GENERICS_FUNCTOR_FOREACH_HPP

#include <cstddef>
#include <functional>

namespace functional {
    // ∀ F A. (A -> void) -> FA -> void
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(A)> &effect, const FA &source);

    // ∀ F A. (A -> size_t -> void) -> FA -> void
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(A, size_t)> &effect, const FA &source);

    // ∀ F A. (const A& -> void) -> FA -> void
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(const A &)> &effect, const FA &source);

    // ∀ F A. (const A& -> size_t -> void) -> FA -> void
    template <typename FA, typename A = typename FA::value_type>
    void foreach (const std::function<void(const A &, size_t)> &effect, const FA &source);

    // ∀ F A B. (A -> B -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, B)> &effect, const FA &a, const FB &b);

    // ∀ F A B. (A -> B -> size_t -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, B, size_t)> &effect, const FA &a, const FB &b);

    // ∀ F A B. (const A& -> B -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, B)> &effect, const FA &a, const FB &b);

    // ∀ F A B. (const A& -> B -> size_t -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, B, size_t)> &effect, const FA &a, const FB &b);

    // ∀ F A B. (A -> const B& -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, const B &)> &effect, const FA &a, const FB &b);

    // ∀ F A B. (A -> const B& -> size_t -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(A, const B &, size_t)> &effect, const FA &a, const FB &b);

    // ∀ F A B. (const A& -> const B& -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, const B &)> &effect, const FA &a, const FB &b);

    // ∀ F A B. (const A& -> const B& -> size_t -> void) -> FA -> FB -> void
    template <typename FA, typename FB, typename A = typename FA::value_type, typename B = typename FB::value_type>
    void foreach (const std::function<void(const A &, const B &, size_t)> &effect, const FA &a, const FB &b);
} // namespace functional

#endif
