#ifndef FUNKY_ITERABLES_FOREACH_HPP
#define FUNKY_ITERABLES_FOREACH_HPP

#include <cstddef>
#include <functional>

namespace funky {
    // (A -> void) -> const FA & -> void
    template <typename FA, typename A>
    void foreach (const std::function<void(A)> &effect, const FA &source);

    // (A -> size_t -> void) -> const FA & -> void
    template <typename FA, typename A>
    void foreach (const std::function<void(A, size_t)> &effect, const FA &source);

    // (const A & -> void) -> const FA & -> void
    template <typename FA, typename A>
    void foreach (const std::function<void(const A &)> &effect, const FA &source);

    // (const A & -> size_t -> void) -> const FA & -> void
    template <typename FA, typename A>
    void foreach (const std::function<void(const A &, size_t)> &effect, const FA &source);

    // (A -> B -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(A, B)> &effect, const FA &a, const FB &b);

    // (A -> B -> size_t -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(A, B, size_t)> &effect, const FA &a, const FB &b);

    // (const A & -> B -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(const A &, B)> &effect, const FA &a, const FB &b);

    // (const A & -> B -> size_t -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(const A &, B, size_t)> &effect, const FA &a, const FB &b);

    // (A -> const B & -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(A, const B &)> &effect, const FA &a, const FB &b);

    // (A -> const B & -> size_t -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(A, const B &, size_t)> &effect, const FA &a, const FB &b);

    // (const A & -> const B & -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(const A &, const B &)> &effect, const FA &a, const FB &b);

    // (const A & -> const B & -> size_t -> void) -> const FA & -> const FB & -> void
    template <typename FA, typename FB, typename A, typename B>
    void foreach (const std::function<void(const A &, const B &, size_t)> &effect, const FA &a, const FB &b);
}

#endif
