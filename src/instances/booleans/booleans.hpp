#ifndef FUNCTIONAL_INSTANCES_BOOLEANS_BOOLEANS_HPP
#define FUNCTIONAL_INSTANCES_BOOLEANS_BOOLEANS_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace functional {
    /**
     * forall F A. (A -> bool) -> FA -> bool
     */
    template <typename FA, typename A = typename FA::value_type>
    bool all(const std::function<bool(A)> &mapper, const FA &source);

    /**
     * forall F. F(bool) -> bool
     */
    template <typename F>
    bool all(const F &source);

    /**
     * forall F A. (A -> bool) -> FA -> bool
     */
    template <typename FA, typename A = typename FA::value_type>
    bool any(const std::function<bool(A)> &mapper, const FA &source);

    /**
     * forall F. F(bool) -> bool
     */
    template <typename F>
    bool any(const F &source);

    /**
     * forall F A. (A -> bool) -> FA -> bool
     */
    template <typename FA, typename A = typename FA::value_type>
    bool at_least(const std::function<bool(A)> &mapper, size_t min, const FA &source);

    /**
     * forall F. F(bool) -> bool
     */
    template <typename F>
    bool at_least(size_t min, const F &source);
} // namespace functional

#endif
