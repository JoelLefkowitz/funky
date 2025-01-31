#ifndef FUNKY_GENERICS_FOLDABLE_FOLD_TPP
#define FUNKY_GENERICS_FOLDABLE_FOLD_TPP

#include "fold.hpp"
#include <numeric>

template <typename B, typename T, typename FA, typename A>
requires Callable<T, B(B, A)>
B funky::fold(const T &folder, const B &initial, const FA &source) {
    return std::reduce(source.begin(), source.end(), initial, folder);
}

#endif
