#ifndef FUNKY_TEMPLATES_CALLABLES_HPP
#define FUNKY_TEMPLATES_CALLABLES_HPP

#include "./apply.hpp"
#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename>
    struct callable_unpack;

    template <typename R, typename... Args>
    struct callable_unpack<R(Args...)> {
        using args  = std::tuple<Args...>;
        using rtype = R;
    };

    template <
        class F,
        typename Sig,
        typename Unpack = callable_unpack<Sig>,
        typename ArgsT  = Unpack::args,
        typename Rtype  = Unpack::rtype>
    concept Callable = applicable<F, ArgsT> &&
        apply_results_in<F, Rtype, ArgsT>;
}

#endif
