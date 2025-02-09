#ifndef FUNKY_GENERICS_CONCEPTS_HPP
#define FUNKY_GENERICS_CONCEPTS_HPP

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename, typename>
    struct is_applicable : std::false_type {};

    template <
        typename T,
        template <typename...> typename Tuple,
        typename... Args>
    struct is_applicable<T, Tuple<Args...>> : std::is_invocable<T, Args...> {};

    template <typename, typename>
    struct is_apply : std::false_type {};

    template <
        typename T,
        template <typename...> typename Tuple,
        typename... Args>
    struct is_apply<T, Tuple<Args...>> : std::invoke_result<T, Args...> {};

    template <typename>
    struct unpack;

    template <typename Returns, typename... Args>
    struct unpack<Returns(Args...)> {
        using args  = std::tuple<Args...>;
        using returns = Returns;
    };

    template <typename T, typename Tuple>
    concept Applicable = is_applicable<T, Tuple>::value;

    template <typename T, typename Rtype, typename Tuple>
    concept Apply =
        std::convertible_to<typename is_apply<T, Tuple>::type, Rtype>;

    template <
        typename T,
        typename Signature,
        typename Args  = unpack<Signature>::args,
        typename Returns = unpack<Signature>::returns>
    concept Callable = Applicable<T, Args> && Apply<T, Returns, Args>;
}

#endif
