#ifndef FUNCTIONAL_INSTANCES_VECTORS_PAGINATOR_TPP
#define FUNCTIONAL_INSTANCES_VECTORS_PAGINATOR_TPP

#include "../numbers/limits.hpp"
#include "elements.tpp"
#include "immutable.tpp"
#include "mutable.tpp"
#include "paginator.hpp"
#include "ranges.tpp"
#include <cmath>
#include <cstddef>
#include <vector>

template <typename T>
functional::Paginator<T>::Paginator(const std::vector<T> &vector, size_t size) : vector(vector)
                                                                               , size(size) {
    page  = 0;
    lower = 0;

    auto limit = static_cast<size_t>(std::floor((vector.size() + size - 1) / size));

    upper = size > 0 ? limit : 0;
}

template <typename T>
std::vector<T> functional::Paginator<T>::current() {
    return functional::slice(vector, page * size, (page + 1) * size);
}

template <typename T>
void functional::Paginator<T>::previous() {
    if (page > lower) {
        --page;
    }
}

template <typename T>
void functional::Paginator<T>::next() {
    if (page + 1 < upper) {
        ++page;
    }
}

template <typename T>
bool functional::Paginator<T>::first() {
    return page == lower;
}

template <typename T>
bool functional::Paginator<T>::last() {
    return upper == 0 || page + 1 == upper;
}

#endif
