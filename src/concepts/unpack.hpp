#ifndef FUNKY_CONCEPTS_UNPACK_HPP
#define FUNKY_CONCEPTS_UNPACK_HPP

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename>
    struct unpack;

    template <typename Returns, typename... Args>
    struct unpack<Returns(Args...)> {
        using args    = std::tuple<Args...>;
        using returns = Returns;
    };
}

#endif
