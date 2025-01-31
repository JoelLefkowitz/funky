#ifndef FUNKY_TEMPLATES_RANGES_HPP
#define FUNKY_TEMPLATES_RANGES_HPP

#include <concepts>
#include <functional>
#include <tuple>
#include <type_traits>

template <typename T>
using elements = std::ranges::range_value_t<T>;

#endif
