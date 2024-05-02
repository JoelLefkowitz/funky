#ifndef FUNCTIONAL_GENERICS_FOLDABLE_FOLD_HPP
#define FUNCTIONAL_GENERICS_FOLDABLE_FOLD_HPP

#include <functional>

namespace functional {
    /**
     * forall F A B. (B -> A -> B) -> B -> FA -> B
     */
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(B, A)> &folder, B initial, const FA &source);

    /**
     * forall F A B. (const B& -> A -> B) -> B -> FA -> B
     */
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(const B &, A)> &folder, B initial, const FA &source);

    /**
     * forall F A B. (B -> const A&-> B) -> B -> FA -> B
     */
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(B, const A &)> &folder, B initial, const FA &source);

    /**
     * forall F A B. (const B& -> const A& -> B) -> B -> FA -> B
     */
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(const B &, const A &)> &folder, B initial, const FA &source);
} // namespace functional

#endif
