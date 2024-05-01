#ifndef PRODUCT_TPP
#define PRODUCT_TPP

#include "product.hpp"
#include <functional>
#include <numeric>

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> functional::product(const std::function<C(A, B)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    for (auto x = a.begin(); x != a.end(); ++x) {
        for (auto y = b.begin(); y != b.end(); ++y) {
            target.push_back(mapper(*x, *y));
        }
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> functional::product(const std::function<C(const A &, B)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    for (auto x = a.begin(); x != a.end(); ++x) {
        for (auto y = b.begin(); y != b.end(); ++y) {
            target.push_back(mapper(*x, *y));
        }
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> functional::product(const std::function<C(A, const B &)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    for (auto x = a.begin(); x != a.end(); ++x) {
        for (auto y = b.begin(); y != b.end(); ++y) {
            target.push_back(mapper(*x, *y));
        }
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> functional::product(const std::function<C(const A &, const B &)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    for (auto x = a.begin(); x != a.end(); ++x) {
        for (auto y = b.begin(); y != b.end(); ++y) {
            target.push_back(mapper(*x, *y));
        }
    }

    return target;
}

#endif