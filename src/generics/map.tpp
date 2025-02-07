
#ifndef FUNKY_GENERICS_FUNCTOR_MAP_TPP
#define FUNKY_GENERICS_FUNCTOR_MAP_TPP

#include "templates.hpp"
#include "../concrete/numbers.hpp"
#include "../concrete/vectors.tpp"
#include "mutable.tpp"
#include "map.hpp"
#include <algorithm>
#include <deque>
#include <map>
#include <numeric>

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


template <typename T>
T funky::min(const std::vector<T> &vec) {
    return vec.empty() ? T() : *std::min_element(vec.begin(), vec.end());
}

template <typename T>
T funky::max(const std::vector<T> &vec) {
    return vec.empty() ? T() : *std::max_element(vec.begin(), vec.end());
}

template <typename T>
size_t funky::index(const std::vector<T> &vec, const T &x) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) == x) {
            return i;
        }
    }

    return 0;
}

template <typename T>
size_t funky::index(
    std::function<bool(const T &)> condition,
    const std::vector<T> &vec
) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (condition(vec.at(i))) {
            return i;
        }
    }

    return 0;
}

template <typename T>
bool funky::contains(const std::vector<T> &vec, const T &x) {
    return std::find(vec.begin(), vec.end(), x) != vec.end();
}

template <typename T>
bool funky::repeats(const std::vector<T> &vec) {
    return vec.size() > unique(vec).size();
}

template <typename T>
bool funky::overlaps(
    const std::vector<T> &source,
    const std::vector<T> &target
) {
    return !intersection(source, target).empty();
}



template <typename T>
std::vector<T> funky::unique(const std::vector<T> &vec) {
    std::vector<T> unique;

    for (auto x : vec) {
        if (!contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename T>
std::vector<T> funky::reverse(const std::vector<T> &vec) {
    std::vector<T> copy;

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
std::vector<T> funky::difference(
    const std::vector<T> &source,
    const std::vector<T> &target
) {
    std::vector<T> unique;

    for (auto x : source) {
        if (!contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename T>
std::vector<T> funky::intersection(
    const std::vector<T> &source,
    const std::vector<T> &target
) {
    std::vector<T> unique;

    for (const auto &x : source) {
        if (contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename T>
std::vector<T> funky::slice(
    const std::vector<T> &vec,
    const size_t start,
    const size_t end
) {
    auto from = static_cast<int>(std::min(start, vec.size()));
    auto to   = static_cast<int>(std::min(end, vec.size()));

    // cppcheck-suppress internalAstError
    return to > from ? std::vector<T>(vec.begin() + from, vec.begin() + to)
                     : std::vector<T>({});
}

template <typename T>
std::vector<T> funky::slice_first(const std::vector<T> &vec, size_t width) {
    return slice(vec, 0, width);
}

template <typename T>
std::vector<T> funky::slice_last(const std::vector<T> &vec, size_t width) {
    return vec.size() > width ? slice(vec, vec.size() - width, vec.size())
                              : vec;
}

template <typename T>
std::vector<T> funky::drop_first(const std::vector<T> &vec, size_t width) {
    return slice(vec, width, vec.size());
}

template <typename T>
std::vector<T> funky::drop_last(const std::vector<T> &vec, size_t width) {
    return vec.size() > width ? slice(vec, 0, vec.size() - width)
                              : std::vector<T>();
}

template <typename T>
std::vector<std::vector<T>> funky::aperture(
    const std::vector<T> &vec,
    size_t width
) {
    std::vector<std::vector<T>> slides;

    if (width == 0 || width > vec.size()) {
        return {};
    }

    for (std::size_t i = 0; i < vec.size() - width + 1; ++i) {
        std::vector<T> slide;

        for (const auto j : range(width)) {
            slide.push_back(vec.at(i + j));
        }

        slides.push_back(slide);
    }

    return slides;
}

template <typename T>
std::vector<T> funky::concat(const std::vector<T> &vec, const T &x) {
    std::vector<T> copy(vec);
    copy.push_back(x);
    return copy;
}

template <typename T>
std::vector<T> funky::concat(
    const std::vector<T> &vec,
    const std::vector<T> &x
) {
    auto copy(vec);
    insert(x, copy);
    return copy;
}

template <typename T>
std::vector<T> funky::flatten(const std::vector<std::vector<T>> &vec) {
    return fold<std::vector<T>>(
        [](const auto &acc, const auto &x) {
            return concat(acc, x);
        },
        {},
        vec
    );
}

template <typename T>
std::vector<T> funky::from_deque(const std::deque<T> &deque) {
    return std::vector<T>({deque.begin(), deque.end()});
}


#endif
