#ifndef FUNKY_GENERICS_MUTABLE_HPP
#define FUNKY_GENERICS_MUTABLE_HPP

#include <cstddef>
#include <vector>

namespace funky {
    // insert ≔ std::vector<A> → std::vector<A> → void
    template <typename A>
    void insert(const std::vector<A> &source, std::vector<A> &target);

    // remove ≔ std::vector<A> → A → void
    template <typename A>
    void remove(std::vector<A> &vec, A x);

    // move_to_back ≔ (A → bool) → std::vector<A> → void
    template <typename A>
    void move_to_back(
        const std::function<bool(A)> &filter,
        std::vector<A> &vec
    );
}

#endif
