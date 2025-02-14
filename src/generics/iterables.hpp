#ifndef FUNKY_GENERICS_ITERABLES_HPP
#define FUNKY_GENERICS_ITERABLES_HPP

#include "../concepts/aliases.hpp"
#include "../concepts/callable.hpp"
#include <deque>
#include <map>
#include <string>
#include <vector>

namespace funky {
    // convert ≔ [ A ] → [ B ]
    template <typename FB, typename FA>
    FB convert(const FA &source);

    // reverse ≔ [ A ] → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA reverse(const FA &source);

    // map ≔ (char → char) → std::string → std::string
    template <typename T>
    requires Callable<T, char(char)>
    std::string map(const T &mapper, const std::string &source);

    // map ≔ (A → B → C) → std::map<A, B> → std::vector<C>
    template <typename C, typename B, typename A, typename T>
    requires Callable<T, C(A, B)>
    std::vector<C> map(const T &mapper, const std::map<A, B> &source);

    // map ≔ (A → size_t → B) → [ A ] → [ B ]
    template <typename FB, typename FA, typename B = Elements<FB>, typename A = Elements<FA>, typename T>
    requires Callable<T, B(A)>
    FB map(const T &mapper, const FA &source);

    // map ≔ (A → B) → [ A ] → [ B ]
    template <typename FB, typename FA, typename B = Elements<FB>, typename A = Elements<FA>, typename T>
    requires Callable<T, B(A, size_t)>
    FB map(const T &mapper, const FA &source);

    // foreach ≔ (A → void) → [ A ] → void
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, void(A)>
    void foreach (const T &effect, const FA &source);

    // foreach ≔ (A → size_t → void) → [ A ] → void
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, void(A, size_t)>
    void foreach (const T &effect, const FA &source);

    // filter ≔ (A → bool) → [ A ] → [ A ]
    template <typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, bool(A)>
    FA filter(const T &condition, const FA &source);

    // fold ≔ (B → A → B) → B → [ A ] → B
    template <typename B, typename FA, typename A = Elements<FA>, typename T>
    requires Callable<T, B(B, A)>
    B fold(const T &folder, const B &initial, const FA &source);

    // concat ≔ [ A ] → A → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA concat(const FA &source, const A &x);

    // concat ≔ [ A ] → [ A ] → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA concat(const FA &source, const FA &x);

    // flatten ≔ std::vector<[ A ]> → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA flatten(const std::vector<FA> &source);

    // slice ≔ [ A ] → size_t → size_t → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA slice(const FA &source, const size_t start, const size_t end);

    // slice_first ≔ [ A ] → size_t → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA slice_first(const FA &source, size_t width);

    // slice_last ≔ [ A ] → size_t → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA slice_last(const FA &source, size_t width);

    // drop_first ≔ [ A ] → size_t → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA drop_first(const FA &source, size_t width);

    // drop_last ≔ [ A ] → size_t → [ A ]
    template <typename FA, typename A = Elements<FA>>
    FA drop_last(const FA &source, size_t width);

    // aperture ≔ [ A ] → size_t → std::vector<[ A ]>
    template <typename FA, typename A = Elements<FA>>
    std::vector<FA> aperture(const FA &source, size_t width);
}

#endif
