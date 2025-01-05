#ifndef FUNKY_GENERICS_FUNCTOR_ZIP_TPP
#define FUNKY_GENERICS_FUNCTOR_ZIP_TPP

#include "zip.hpp"
#include <functional>
#include <numeric>

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> funky::zip(const std::function<C(A, B)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        target.push_back(mapper(*x, *y));
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> funky::zip(const std::function<C(const A &, B)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        target.push_back(mapper(*x, *y));
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> funky::zip(const std::function<C(A, const B &)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        target.push_back(mapper(*x, *y));
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B, typename C>
F<C> funky::zip(const std::function<C(const A &, const B &)> &mapper, const F<A> &a, const F<B> &b) {
    F<C> target;

    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        target.push_back(mapper(*x, *y));
    }

    return target;
}

#endif
