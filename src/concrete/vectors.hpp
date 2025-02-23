#ifndef FUNKY_CONCRETE_VECTORS_HPP
#define FUNKY_CONCRETE_VECTORS_HPP

#include "../concepts/aliases.hpp"
#include "../concepts/callable.hpp"
#include <cstddef>
#include <deque>
#include <utility>
#include <vector>

namespace funky {
    // range ≔ size_t → std::vector<size_t>
    std::vector<size_t> range(size_t limit);

    // range ≔ A → A → A → std::vector<A>
    template <typename A>
    std::vector<A> range(A start, A stop, A step = 1);

    // linspace ≔ A → A → size_t → std::vector<A>
    template <typename A>
    std::vector<A> linspace(A start, A stop, size_t count);

    // enumerate ≔ std::vector<A> → std::vector<Indexes<A>>
    template <typename A>
    std::vector<Indexes<A>> enumerate(const std::vector<A> &vec);
}

#endif
