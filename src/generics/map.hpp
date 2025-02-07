#ifndef FUNKY_ITERABLES_MAP_HPP
#define FUNKY_ITERABLES_MAP_HPP

#include "templates.hpp"
#include <map>
#include <string>
#include <vector>
#include <deque>

namespace funky {
    // map ≔ (char → char) → std::string → std::string
    template <typename T>
    requires Callable<T, char(char)>
    std::string map(const T &mapper, const std::string &source);

    // map ≔ (A → B → C) → std::map<A, B> → std::vector<C>
    template <typename C, typename B, typename A, typename T>
    requires Callable<T, C(A, B)>
    std::vector<C> map(const T &mapper, const std::map<A, B> &source);

    // map ≔ (A → B) → [ A ] → [ B ]
    template <
        typename FB,
        typename FA,
        typename B = Elements<FB>,
        typename A = Elements<FA>,
        typename T>
    requires Callable<T, B(A)>
    FB map(const T &mapper, const FA &source);

    // foreach ≔ (A → void) → [ A ] → void
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, void(A)>
    void foreach (const T &effect, const FA &source);

    // foreach ≔ (A → size_t → void) → [ A ] → void
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, void(A, size_t)>
    void foreach (const T &effect, const FA &source);

    // foreach ≔ (A → B → void) → [ A ] → [ B ] → void
    template <
        typename FA,
        typename FB,
        typename A = Elements<FA>,
        typename B = Elements<FB>,
        typename T>
    requires Callable<T, void(A, B)>
    void foreach (const T &effect, const FA &a, const FB &b);

    // foreach ≔ (A → B → size_t → void) → [ A ] → [ B ] → void
    template <
        typename FA,
        typename FB,
        typename A = Elements<FA>,
        typename B = Elements<FB>,
        typename T>
    requires Callable<T, void(A, B, size_t)>
    void foreach (const T &effect, const FA &a, const FB &b);

    // filter ≔ (A → bool) → [ A ] → [ A ]
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, bool(A)>
    FA filter(const T &condition, const FA &source);

    // fold ≔ (B → A → B) → B → [ A ] → B
    template <typename B, typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, B(B, A)>
    B fold(const T &folder, const B &initial, const FA &source);

    // min ≔ std::vector<T> → T
    template <typename T>
    T min(const std::vector<T> &vec);

    // max ≔ std::vector<T> → T
    template <typename T>
    T max(const std::vector<T> &vec);

    // index ≔ std::vector<T> → T → size_t
    template <typename T>
    size_t index(const std::vector<T> &vec, const T &x);

    // index ≔ (const T & → bool) → std::vector<T> → size_t
    template <typename T>
    size_t index(
        std::function<bool(const T &)> condition,
        const std::vector<T> &vec
    );

    // contains ≔ std::vector<T> → T → bool
    template <typename T>
    bool contains(const std::vector<T> &vec, const T &x);

    // repeats ≔ std::vector<T> → bool
    template <typename T>
    bool repeats(const std::vector<T> &vec);

    // overlaps ≔ std::vector<T> → std::vector<T> → bool
    template <typename T>
    bool overlaps(const std::vector<T> &source, const std::vector<T> &target);

    // unique ≔ std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> unique(const std::vector<T> &vec);

    // reverse ≔ std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> reverse(const std::vector<T> &vec);

    // difference ≔ std::vector<T> → std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> difference(
        const std::vector<T> &source,
        const std::vector<T> &target
    );

    // intersection ≔ std::vector<T> → std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> intersection(
        const std::vector<T> &source,
        const std::vector<T> &target
    );

    // slice ≔ std::vector<T> → size_t → size_t → std::vector<T>
    template <typename T>
    std::vector<T> slice(
        const std::vector<T> &vec,
        const size_t start,
        const size_t end
    );

    // slice_first ≔ std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> slice_first(const std::vector<T> &vec, size_t width);

    // slice_last ≔ std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> slice_last(const std::vector<T> &vec, size_t width);

    // drop_first ≔ std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> drop_first(const std::vector<T> &vec, size_t width);

    // drop_last ≔ std::vector<T> → size_t → std::vector<T>
    template <typename T>
    std::vector<T> drop_last(const std::vector<T> &vec, size_t width);

    // aperture ≔ std::vector<T> → size_t → std::vector<std::vector<T>>
    template <typename T>
    std::vector<std::vector<T>> aperture(
        const std::vector<T> &vec,
        size_t width
    );

    // concat ≔ std::vector<T> → T → std::vector<T>
    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const T &x);

    // concat ≔ std::vector<T> → std::vector<T> → std::vector<T>
    template <typename T>
    std::vector<T> concat(const std::vector<T> &vec, const std::vector<T> &x);

    // flatten ≔ std::vector<std::vector<T>> → std::vector<T>
    template <typename T>
    std::vector<T> flatten(const std::vector<std::vector<T>> &vec);

    // from_deque ≔ std::deque<T> → std::vector<T>
    template <typename T>
    std::vector<T> from_deque(const std::deque<T> &deque);
}

#endif
