#ifndef FUNKY_GENERICS_FUNCTOR_PAIR_TPP
#define FUNKY_GENERICS_FUNCTOR_PAIR_TPP

#include "pair.hpp"
#include <functional>
#include <numeric>

template <template <typename...> typename F, typename A, typename B>
F<B> funky::pair(const std::function<B(A, A)> &mapper, const F<A> &source) {
    F<B> target;

    if (!source.empty()) {
        for (auto i = source.begin(); (i + 1) != source.end(); ++i) {
            target.push_back(mapper(*i, *(i + 1)));
        }
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B>
F<B> funky::pair(const std::function<B(const A &, A)> &mapper, const F<A> &source) {
    F<B> target;

    if (!source.empty()) {
        for (auto i = source.begin(); (i + 1) != source.end(); ++i) {
            target.push_back(mapper(*i, *(i + 1)));
        }
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B>
F<B> funky::pair(const std::function<B(A, const A &)> &mapper, const F<A> &source) {
    F<B> target;

    if (!source.empty()) {
        for (auto i = source.begin(); (i + 1) != source.end(); ++i) {
            target.push_back(mapper(*i, *(i + 1)));
        }
    }

    return target;
}

template <template <typename...> typename F, typename A, typename B>
F<B> funky::pair(const std::function<B(const A &, const A &)> &mapper, const F<A> &source) {
    F<B> target;

    if (!source.empty()) {
        for (auto i = source.begin(); (i + 1) != source.end(); ++i) {
            target.push_back(mapper(*i, *(i + 1)));
        }
    }

    return target;
}

#endif
