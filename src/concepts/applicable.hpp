#ifndef FUNKY_CONCEPTS_APPLICABLE_HPP
#define FUNKY_CONCEPTS_APPLICABLE_HPP

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename, typename>
    struct is_applicable : std::false_type {};

    template <
        typename T,
        template <typename...>
        typename Tuple,
        typename... Args>
    struct is_applicable<T, Tuple<Args...>> : std::is_invocable<T, Args...> {};

    template <typename T, typename Tuple>
    concept Applicable = is_applicable<T, Tuple>::value;
}

#endif
