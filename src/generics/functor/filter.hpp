#ifndef FUNKY_GENERICS_FUNCTOR_FILTER_HPP
#define FUNKY_GENERICS_FUNCTOR_FILTER_HPP

#include <functional>

namespace funky {
    // (A -> bool) -> const FA & -> FA
    template <typename FA, typename A = typename FA::value_type>
    FA filter(const std::function<bool(A)> &condition, const FA &source);

    // (const A & -> bool) -> const FA & -> FA
    template <typename FA, typename A = typename FA::value_type>
    FA filter(const std::function<bool(const A &)> &condition, const FA &source);
} // namespace functional

#endif
