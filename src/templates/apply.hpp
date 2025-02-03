#ifndef FUNKY_TEMPLATES_APPLY_HPP
#define FUNKY_TEMPLATES_APPLY_HPP

#include "./applicable.hpp"
#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename, typename>
    struct apply_result : std::false_type {};

    template <typename Func, template <typename...> typename Tuple, typename... Args>
    struct apply_result<Func, Tuple<Args...>> : std::invoke_result<Func, Args...> {};

    template <typename F, typename Rtype, typename Tuple>
    concept apply_results_in = std::convertible_to<typename apply_result<F, Tuple>::type, Rtype>;
}

#endif
