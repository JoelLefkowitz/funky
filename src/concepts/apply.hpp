#ifndef FUNKY_CONCEPTS_APPLY_HPP
#define FUNKY_CONCEPTS_APPLY_HPP

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename, typename>
    struct is_apply : std::false_type {};

    template <
        typename T,
        template <typename...>
        typename Tuple,
        typename... Args>
    struct is_apply<T, Tuple<Args...>> : std::invoke_result<T, Args...> {};

    template <typename T, typename Returns, typename Tuple>
    concept Apply =
        std::convertible_to<typename is_apply<T, Tuple>::type, Returns>;
}

#endif
