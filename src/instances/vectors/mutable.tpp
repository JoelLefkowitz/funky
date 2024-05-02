#ifndef FUNCTIONAL_INSTANCES_VECTORS_MUTABLE_TPP
#define FUNCTIONAL_INSTANCES_VECTORS_MUTABLE_TPP

#ifndef MUTABLE_TPP
#define MUTABLE_TPP

#include "../../generics/foldable/fold.tpp"
#include "../../generics/functor/map.tpp"
#include "../numbers/limits.hpp"
#include "immutable.tpp"
#include "mutable.hpp"
#include <algorithm>
#include <functional>
#include <numeric>

template <typename T>
void functional::insert(const std::vector<T> &source, std::vector<T> &target) {
    target.insert(target.end(), source.begin(), source.end());
}

template <typename T>
void functional::erase(std::vector<T> &vec, T x) {
    auto removed = std::remove(vec.begin(), vec.end(), x);
    vec.erase(removed, vec.end());
}

template <typename T>
void functional::move_to_back(const std::function<bool(T)> &filter, std::vector<T> &vec) {
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        if (filter(*i)) {
            auto x = std::move(*i);
            vec.erase(i);
            vec.insert(vec.end(), x);
            break;
        }
    }
}

#endif
#endif
