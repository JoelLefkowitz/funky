#ifndef FUNKY_CONCEPTS_CALLABLE_HPP
#define FUNKY_CONCEPTS_CALLABLE_HPP

#include "applicable.hpp"
#include "apply.hpp"
#include "unpack.hpp"
#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

namespace funky {
    template <
        typename T,
        typename Signature,
        typename Args    = unpack<Signature>::args,
        typename Returns = unpack<Signature>::returns>
    concept Callable = Applicable<T, Args> && Apply<T, Returns, Args>;
}

#endif
