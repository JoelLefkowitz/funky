#ifndef FUNKY_GENERICS_FOLDABLE_FOLD_HPP
#define FUNKY_GENERICS_FOLDABLE_FOLD_HPP

#include <functional>

namespace funky {
    // (B -> A -> B) -> B -> const FA & -> B
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(B, A)> &folder, B initial, const FA &source);

    // (const B & -> A -> B) -> B -> const FA & -> B
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(const B &, A)> &folder, B initial, const FA &source);

    // (B -> const A & -> B) -> B -> const FA & -> B
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(B, const A &)> &folder, B initial, const FA &source);

    // (const B & -> const A & -> B) -> B -> const FA & -> B
    template <typename FA, typename A = typename FA::value_type, typename B>
    B fold(const std::function<B(const B &, const A &)> &folder, B initial, const FA &source);
} // namespace functional

#endif
