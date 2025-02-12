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
FA funky::reverse(const FA &source) {
    FA copy;

    if (source.empty()) {
        return copy;
    }

    for (auto i = source.rbegin(); i != source.rend(); ++i) {
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
        [&mapper](const auto &x) {
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

template <typename FB, typename FA, typename B, typename A, typename T>
requires funky::Callable<T, B(A, size_t)>
FB funky::map(const T &mapper, const FA &source) {
    FB target;
    size_t i = 0;

    for (const auto &x : source) {
        target.push_back(mapper(x, i));
        i++;
    }

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
    size_t i = 0;

    for (const auto &x : source) {
        effect(x, i);
        i++;
    }
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, bool(A)>
FA funky::filter(const T &condition, const FA &source) {
    FA filtered;

    auto inserter = std::back_inserter(filtered);

    for (const auto &x : source) {
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
FA funky::concat(const FA &source, const A &x) {
    FA copy(source);
    copy.push_back(x);
    return copy;
}

template <typename FA, typename A>
FA funky::concat(const FA &source, const FA &x) {
    auto copy(source);
    insert(x, copy);
    return copy;
}

template <typename FA, typename A>
FA funky::flatten(const std::vector<FA> &source) {
    return fold<FA>(
        [](const auto &acc, const auto &x) {
            return concat(acc, x);
        },
        {},
        source
    );
}

template <typename FA, typename A>
FA funky::slice(const FA &source, const size_t start, const size_t end) {
    auto from = static_cast<int>(std::min(start, source.size()));
    auto to   = static_cast<int>(std::min(end, source.size()));

    // cppcheck-suppress internalAstError
    return to > from ? FA(source.begin() + from, source.begin() + to) : FA({});
}

template <typename FA, typename A>
FA funky::slice_first(const FA &source, size_t width) {
    return slice(source, 0, width);
}

template <typename FA, typename A>
FA funky::slice_last(const FA &source, size_t width) {
    return source.size() > width
        ? slice(source, source.size() - width, source.size())
        : source;
}

template <typename FA, typename A>
FA funky::drop_first(const FA &source, size_t width) {
    return slice(source, width, source.size());
}

template <typename FA, typename A>
FA funky::drop_last(const FA &source, size_t width) {
    return source.size() > width ? slice(source, 0, source.size() - width)
                                 : FA();
}

template <typename FA, typename A>
std::vector<FA> funky::aperture(const FA &source, size_t width) {
    std::vector<FA> slides;

    if (width == 0 || width > source.size()) {
        return {};
    }

    for (size_t i = 0; i < source.size() - width + 1; ++i) {
        FA slide;

        for (size_t j = 0; j < width; ++j) {
            slide.push_back(source.at(i + j));
        }

        slides.push_back(slide);
    }

    return slides;
}

#endif
