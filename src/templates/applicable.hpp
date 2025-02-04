#ifndef FUNKY_TEMPLATES_APPLICABLE_HPP
#define FUNKY_TEMPLATES_APPLICABLE_HPP

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename, typename>
    struct is_applicable : std::false_type {};

    template <
        typename Func,
        template <typename...>
        typename Tuple,
        typename... Args>
    struct is_applicable<Func, Tuple<Args...>>
        : std::is_invocable<Func, Args...> {};

    template <typename F, typename Tuple>
    concept applicable = is_applicable<F, Tuple>::value;
}

#endif
