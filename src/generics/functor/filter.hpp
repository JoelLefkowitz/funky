#ifndef FUNCTIONAL_GENERICS_FUNCTOR_FILTER_HPP
#define FUNCTIONAL_GENERICS_FUNCTOR_FILTER_HPP

#include <functional>

namespace functional {
    /**
     * ∀ F A. (A -> bool) -> FA -> FA
     */
    template <typename FA, typename A = typename FA::value_type>
    FA filter(const std::function<bool(A)> &condition, const FA &source);

    /**
     * ∀ F A. (const A& -> bool) -> FA -> FA
     */
    template <typename FA, typename A = typename FA::value_type>
    FA filter(const std::function<bool(const A &)> &condition, const FA &source);
} // namespace functional

#endif
