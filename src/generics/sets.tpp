#ifndef FUNKY_GENERICS_SETS_TPP
#define FUNKY_GENERICS_SETS_TPP

#include "../concepts/callable.hpp"
#include "../concrete/numbers.hpp"
#include "../concrete/vectors.tpp"
#include "mutable.tpp"
#include "sets.hpp"
#include <algorithm>
#include <deque>
#include <map>
#include <numeric>

template <typename FA, typename A>
bool funky::contains(const FA &vec, const A &x) {
    return std::find(vec.begin(), vec.end(), x) != vec.end();
}

template <typename FA, typename A>
bool funky::is_unique(const FA &vec) {
    FA unique;

    for (auto x : vec) {
        if (contains(unique, x)) {
            return false;
        } else {
            unique.push_back(x);
        }
    }

    return true;
}

template <typename FA, typename A>
FA funky::unique(const FA &vec) {
    FA unique;

    for (auto x : vec) {
        if (!contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename FA, typename A>
bool funky::intersects(const FA &source, const FA &target) {
    return !intersection(source, target).empty();
}

template <typename FA, typename A>
FA funky::intersection(const FA &source, const FA &target) {
    FA unique;

    for (const auto &x : source) {
        if (contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename FA, typename A>
FA funky::difference(const FA &source, const FA &target) {
    FA unique;

    for (auto x : source) {
        if (!contains(target, x) && !contains(unique, x)) {
            unique.push_back(x);
        }
    }

    return unique;
}

template <typename FA, typename A>
size_t funky::index(const FA &vec, const A &x) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) == x) {
            return i;
        }
    }

    return 0;
}

template <typename FA, typename A, typename T>
requires funky::Callable<T, bool(A)>
size_t funky::find(const T &condition, const FA &source) {
    for (size_t i = 0; i < source.size(); ++i) {
        if (condition(source.at(i))) {
            return i;
        }
    }

    return 0;
}

template <typename FA, typename A>
A funky::min(const FA &vec, A empty) {
    return vec.empty() ? empty : *std::min_element(vec.begin(), vec.end());
}

template <typename FA, typename A>
A funky::max(const FA &vec, A empty) {
    return vec.empty() ? empty : *std::max_element(vec.begin(), vec.end());
}

#endif
