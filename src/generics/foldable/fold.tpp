#ifndef FOLD_TPP
#define FOLD_TPP

#include "fold.hpp"
#include <functional>
#include <numeric>

template <typename FA, typename A, typename B>
B functional::fold(const std::function<B(B, A)> &folder, B initial, const FA &source) {
    return std::reduce(source.begin(), source.end(), initial, folder);
}

template <typename FA, typename A, typename B>
B functional::fold(const std::function<B(const B &, A)> &folder, B initial, const FA &source) {
    return std::reduce(source.begin(), source.end(), initial, folder);
}

template <typename FA, typename A, typename B>
B functional::fold(const std::function<B(B, const A &)> &folder, B initial, const FA &source) {
    return std::reduce(source.begin(), source.end(), initial, folder);
}

template <typename FA, typename A, typename B>
B functional::fold(const std::function<B(const B &, const A &)> &folder, B initial, const FA &source) {
    return std::reduce(source.begin(), source.end(), initial, folder);
}

#endif