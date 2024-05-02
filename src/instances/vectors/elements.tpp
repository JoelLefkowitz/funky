#ifndef FUNCTIONAL_INSTANCES_VECTORS_ELEMENTS_TPP
#define FUNCTIONAL_INSTANCES_VECTORS_ELEMENTS_TPP

#include "../../generics/foldable/fold.tpp"
#include "../../generics/functor/map.tpp"
#include "elements.hpp"
#include "immutable.tpp"
#include <algorithm>
#include <functional>
#include <numeric>

template <typename T>
T functional::min(const std::vector<T> &vec) {
    return vec.empty() ? T() : *std::min_element(vec.begin(), vec.end());
}

template <typename T>
T functional::max(const std::vector<T> &vec) {
    return vec.empty() ? T() : *std::max_element(vec.begin(), vec.end());
}

template <typename T>
size_t functional::index(const std::vector<T> &vec, const T &x) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) == x) {
            return i;
        }
    }

    return 0;
}

template <typename T>
size_t functional::index(std::function<bool(const T &)> condition, const std::vector<T> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (condition(vec.at(i))) {
            return i;
        }
    }

    return 0;
}

template <typename T>
bool functional::contains(const std::vector<T> &vec, const T &x) {
    return std::find(vec.begin(), vec.end(), x) != vec.end();
}

template <typename T>
bool functional::repeats(const std::vector<T> &vec) {
    return vec.size() > unique(vec).size();
}

template <typename T>
bool functional::overlaps(const std::vector<T> &source, const std::vector<T> &target) {
    return !intersection(source, target).empty();
}

#endif
