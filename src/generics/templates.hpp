#ifndef FUNKY_TEMPLATES_RANGES_HPP
#define FUNKY_TEMPLATES_RANGES_HPP

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

    template <typename, typename>
    struct apply_result : std::false_type {};

    template <
        typename Func,
        template <typename...>
        typename Tuple,
        typename... Args>
    struct apply_result<Func, Tuple<Args...>>
        : std::invoke_result<Func, Args...> {};

    template <typename F, typename Rtype, typename Tuple>
    concept apply_results_in =
        std::convertible_to<typename apply_result<F, Tuple>::type, Rtype>;

    template <typename>
    struct callable_unpack;

    template <typename RType, typename... Args>
    struct callable_unpack<RType(Args...)> {
        using args  = std::tuple<Args...>;
        using rtype = RType;
    };

    template <
        class F,
        typename Sig,
        typename Args  = callable_unpack<Sig>::args,
        typename RType = callable_unpack<Sig>::rtype>
    concept Callable = applicable<F, Args> && apply_results_in<F, RType, Args>;

    template <typename T>
    using Elements = std::ranges::range_value_t<T>;

    template <typename T>
    using Indexed = std::pair<size_t, T>;
}

#endif
