#ifndef FUNKY_GENERICS_ITERABLES_TPP
#define FUNKY_GENERICS_ITERABLES_TPP

#include "../concepts/callable.hpp"
#include "../concrete/numbers.hpp"
#include "../concrete/vectors.tpp"
#include "iterables.hpp"
#include "mutable.tpp"
#include <algorithm>
#include <deque>
#include <map>
#include <numeric>

template <typename FB, typename FA>
FB funky::convert(const FA &source) {
    return {source.begin(), source.end()};
}

template <typename FA, typename A>
FA funky::reverse(const FA &vec) {
    FA copy;

    if (vec.empty()) {
        return copy;
    }

    auto size = --vec.begin();

    for (auto i = --vec.end(); i != size; --i) {
        copy.push_back(*i);
    }

    return copy;
}

template <typename T>
requires funky::Callable<T, char(char)>
std::string funky::map(const T &mapper, const std::string &source) {
    std::string target;
    std::transform(
        source.begin(),
        source.end(),
        std::back_inserter(target),
        mapper
    );
    return target;
}

template <typename C, typename B, typename A, typename T>
requires funky::Callable<T, C(A, B)>
std::vector<C> funky::map(const T &mapper, const std::map<A, B> &source) {
    std::vector<C> target;

    std::transform(
        source.begin(),
        source.end(),
        std::back_inserter(target),
        [&mapper](auto &x) {
            return mapper(x.first, x.second);
        }
    );

    return target;
}

template <typename FB, typename FA, typename B, typename A, typename T>
requires funky::Callable<T, B(A)>
FB funky::map(const T &mapper, const FA &source) {
    FB target;
    std::transform(
        source.begin(),
        source.end(),
        std::back_inserter(target),
        mapper
    );
    return target;
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, void(A)>
void funky::foreach (const T &effect, const FA &source) {
    std::for_each(source.begin(), source.end(), effect);
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, void(A, size_t)>
void funky::foreach (const T &effect, const FA &source) {
    for (auto x = source.begin(); x != source.end(); ++x) {
        auto index = static_cast<size_t>(x - source.begin());
        effect(*x, index);
    }
}

template <typename FA, typename FB, typename A, typename B, typename T>
requires funky::Callable<T, void(A, B)>
void funky::foreach (const T &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        effect(*x, *y);
    }
}

template <typename FA, typename FB, typename A, typename B, typename T>
requires funky::Callable<T, void(A, B, size_t)>
void funky::foreach (const T &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        auto index = static_cast<size_t>(x - a.begin());
        effect(*x, *y, index);
    }
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, bool(A)>
FA funky::filter(const T &condition, const FA &source) {
    FA filtered;

    auto inserter = std::back_inserter(filtered);

    for (auto x : source) {
        if (condition(x)) {
            *inserter = x;
        }
    }

    return filtered;
}

template <typename B, typename FA, typename A, typename T>
requires funky::Callable<T, B(B, A)>
B funky::fold(const T &folder, const B &initial, const FA &source) {
    return std::reduce(source.begin(), source.end(), initial, folder);
}

template <typename FA, typename A>
FA funky::concat(const FA &vec, const A &x) {
    FA copy(vec);
    copy.push_back(x);
    return copy;
}

template <typename FA, typename A>
FA funky::concat(const FA &vec, const FA &x) {
    auto copy(vec);
    insert(x, copy);
    return copy;
}

template <typename FA, typename A>
FA funky::flatten(const std::vector<FA> &vec) {
    return fold<FA>(
        [](const auto &acc, const auto &x) {
            return concat(acc, x);
        },
        {},
        vec
    );
}

template <typename FA, typename A>
FA funky::slice(const FA &vec, const size_t start, const size_t end) {
    auto from = static_cast<int>(std::min(start, vec.size()));
    auto to   = static_cast<int>(std::min(end, vec.size()));

    // cppcheck-suppress internalAstError
    return to > from ? FA(vec.begin() + from, vec.begin() + to) : FA({});
}

template <typename FA, typename A>
FA funky::slice_first(const FA &vec, size_t width) {
    return slice(vec, 0, width);
}

template <typename FA, typename A>
FA funky::slice_last(const FA &vec, size_t width) {
    return vec.size() > width ? slice(vec, vec.size() - width, vec.size())
                              : vec;
}

template <typename FA, typename A>
FA funky::drop_first(const FA &vec, size_t width) {
    return slice(vec, width, vec.size());
}

template <typename FA, typename A>
FA funky::drop_last(const FA &vec, size_t width) {
    return vec.size() > width ? slice(vec, 0, vec.size() - width) : FA();
}

template <typename FA, typename A>
std::vector<FA> funky::aperture(const FA &vec, size_t width) {
    std::vector<FA> slides;

    if (width == 0 || width > vec.size()) {
        return {};
    }

    for (std::size_t i = 0; i < vec.size() - width + 1; ++i) {
        FA slide;

        for (const auto j : range(width)) {
            slide.push_back(vec.at(i + j));
        }

        slides.push_back(slide);
    }

    return slides;
}

#endif
