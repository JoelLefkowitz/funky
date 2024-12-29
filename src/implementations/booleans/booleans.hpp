#ifndef FUNKY_IMPLEMENTATIONS_BOOLEANS_BOOLEANS_HPP
#define FUNKY_IMPLEMENTATIONS_BOOLEANS_BOOLEANS_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace funky {
    // (A -> bool) -> const FA & -> bool
    template <typename FA, typename A = typename FA::value_type>
    bool all(const std::function<bool(A)> &mapper, const FA &source);

    // const F & -> bool
    template <typename F>
    bool all(const F &source);

    // (A -> bool) -> const FA & -> bool
    template <typename FA, typename A = typename FA::value_type>
    bool any(const std::function<bool(A)> &mapper, const FA &source);

    // const F & -> bool
    template <typename F>
    bool any(const F &source);

    // (A -> bool) -> size_t -> const FA & -> bool
    template <typename FA, typename A = typename FA::value_type>
    bool at_least(const std::function<bool(A)> &mapper, size_t min, const FA &source);

    // size_t -> const F & -> bool
    template <typename F>
    bool at_least(size_t min, const F &source);
} // namespace functional

#endif
