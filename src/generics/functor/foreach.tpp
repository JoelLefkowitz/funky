#ifndef FUNKY_GENERICS_FUNCTOR_FOREACH_TPP
#define FUNKY_GENERICS_FUNCTOR_FOREACH_TPP

#include "foreach.hpp"
#include <algorithm>
#include <cstddef>
#include <functional>

// ∀ F A. (A -> void) -> FA -> void
template <typename FA, typename A>
void funky::foreach (const std::function<void(A)> &effect, const FA &source) {
    std::for_each(source.begin(), source.end(), effect);
}

template <typename FA, typename A>
void funky::foreach (const std::function<void(A, size_t)> &effect, const FA &source) {
    for (auto x = source.begin(); x != source.end(); ++x) {
        auto index = static_cast<size_t>(x - source.begin());
        effect(*x, index);
    }
}

template <typename FA, typename A>
void funky::foreach (const std::function<void(const A &)> &effect, const FA &source) {
    std::for_each(source.begin(), source.end(), effect);
}

template <typename FA, typename A>
void funky::foreach (const std::function<void(const A &, size_t)> &effect, const FA &source) {
    for (auto x = source.begin(); x != source.end(); ++x) {
        auto index = static_cast<size_t>(x - source.begin());
        effect(*x, index);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(A, B)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        effect(*x, *y);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(A, B, size_t)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        auto index = static_cast<size_t>(x - a.begin());
        effect(*x, *y, index);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(const A &, B)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        effect(*x, *y);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(const A &, B, size_t)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        auto index = static_cast<size_t>(x - a.begin());
        effect(*x, *y, index);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(A, const B &)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        effect(*x, *y);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(A, const B &, size_t)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        auto index = static_cast<size_t>(x - a.begin());
        effect(*x, *y, index);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(const A &, const B &)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        effect(*x, *y);
    }
}

template <typename FA, typename FB, typename A, typename B>
void funky::foreach (const std::function<void(const A &, const B &, size_t)> &effect, const FA &a, const FB &b) {
    auto x = a.begin();
    auto y = b.begin();

    for (; x != a.end() && y != b.end(); ++x, ++y) {
        auto index = static_cast<size_t>(x - a.begin());
        effect(*x, *y, index);
    }
}

#endif
