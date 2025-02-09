#ifndef FUNKY_GENERICS_SETS_HPP
#define FUNKY_GENERICS_SETS_HPP

#include "concepts.hpp"
#include <deque>
#include <map>
#include <string>
#include <vector>

namespace funky {
    // min ≔ std::vector<A> → A → A
    template <typename A>
    A min(const std::vector<A> &vec, A empty);

    // max ≔ std::vector<A> → A → A
    template <typename A>
    A max(const std::vector<A> &vec, A empty);

    // index ≔ std::vector<A> → A → size_t
    template <typename A>
    size_t index(const std::vector<A> &vec, const A &x);

    // index ≔ (const A & → bool) → std::vector<A> → size_t
    template <typename A>
    size_t index(
        std::function<bool(const A &)> condition,
        const std::vector<A> &vec
    );

    // contains ≔ std::vector<A> → A → bool
    template <typename A>
    bool contains(const std::vector<A> &vec, const A &x);

    // repeats ≔ std::vector<A> → bool
    template <typename A>
    bool repeats(const std::vector<A> &vec);

    // overlaps ≔ std::vector<A> → std::vector<A> → bool
    template <typename A>
    bool overlaps(const std::vector<A> &source, const std::vector<A> &target);

    // unique ≔ std::vector<A> → std::vector<A>
    template <typename A>
    std::vector<A> unique(const std::vector<A> &vec);

    // difference ≔ std::vector<A> → std::vector<A> → std::vector<A>
    template <typename A>
    std::vector<A> difference(
        const std::vector<A> &source,
        const std::vector<A> &target
    );

    // intersection ≔ std::vector<A> → std::vector<A> → std::vector<A>
    template <typename A>
    std::vector<A> intersection(
        const std::vector<A> &source,
        const std::vector<A> &target
    );
}

#endif
