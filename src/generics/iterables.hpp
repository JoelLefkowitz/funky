#ifndef FUNKY_GENERICS_ITERABLES_HPP
#define FUNKY_GENERICS_ITERABLES_HPP

#include "concepts.hpp"
#include "aliases.hpp"
#include <deque>
#include <map>
#include <string>
#include <vector>

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

    // reverse ≔ std::vector<A> → std::vector<A>
    template <typename A>
    std::vector<A> reverse(const std::vector<A> &vec);

    // slice ≔ std::vector<A> → size_t → size_t → std::vector<A>
    template <typename A>
    std::vector<A> slice(
        const std::vector<A> &vec,
        const size_t start,
        const size_t end
    );

    // slice_first ≔ std::vector<A> → size_t → std::vector<A>
    template <typename A>
    std::vector<A> slice_first(const std::vector<A> &vec, size_t width);

    // slice_last ≔ std::vector<A> → size_t → std::vector<A>
    template <typename A>
    std::vector<A> slice_last(const std::vector<A> &vec, size_t width);

    // drop_first ≔ std::vector<A> → size_t → std::vector<A>
    template <typename A>
    std::vector<A> drop_first(const std::vector<A> &vec, size_t width);

    // drop_last ≔ std::vector<A> → size_t → std::vector<A>
    template <typename A>
    std::vector<A> drop_last(const std::vector<A> &vec, size_t width);

    // aperture ≔ [ A ] → size_t → std::vector<[ A ]>
    template <typename FA, typename A = Elements<FA>>
    std::vector<FA> aperture(const FA &vec, size_t width);

    // concat ≔ std::vector<A> → A → std::vector<A>
    template <typename A>
    std::vector<A> concat(const std::vector<A> &vec, const A &x);

    // concat ≔ std::vector<A> → std::vector<A> → std::vector<A>
    template <typename A>
    std::vector<A> concat(const std::vector<A> &vec, const std::vector<A> &x);

    // flatten ≔ std::vector<std::vector<A>> → std::vector<A>
    template <typename A>
    std::vector<A> flatten(const std::vector<std::vector<A>> &vec);
}

#endif
