#ifndef FUNKY_IMPLEMENTATIONS_VECTORS_ELEMENTS_TPP
#define FUNKY_IMPLEMENTATIONS_VECTORS_ELEMENTS_TPP

#include "../../generics/foldable/fold.tpp"
#include "../../generics/functor/map.tpp"
#include "elements.hpp"
#include "immutable.tpp"
#include <algorithm>
#include <functional>
#include <numeric>

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
size_t funky::index(std::function<bool(const T &)> condition, const std::vector<T> &vec) {
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
bool funky::overlaps(const std::vector<T> &source, const std::vector<T> &target) {
    return !intersection(source, target).empty();
}

#endif
