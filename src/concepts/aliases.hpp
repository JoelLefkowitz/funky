#ifndef FUNKY_CONCEPTS_ALIASES_HPP
#define FUNKY_CONCEPTS_ALIASES_HPP

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <typename A>
    using Elements = std::ranges::range_value_t<A>;

    template <typename A>
    using Indexes = std::pair<size_t, A>;

    template <typename A>
    using Pairs = std::pair<A, A>;
}

#endif
