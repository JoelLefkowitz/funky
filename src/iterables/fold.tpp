#ifndef FUNKY_GENERICS_FOLDABLE_FOLD_TPP
#define FUNKY_GENERICS_FOLDABLE_FOLD_TPP

#include "../templates/callables.hpp"
#include "../templates/ranges.hpp"
#include "fold.hpp"
#include <numeric>

template <typename B, typename FA, typename A, typename T>
requires funky::Callable<T, B(B, A)>
B funky::fold(const T &folder, const B &initial, const FA &source) {
    return std::reduce(source.begin(), source.end(), initial, folder);
}

#endif
