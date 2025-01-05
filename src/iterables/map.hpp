#ifndef FUNKY_ITERABLES_MAP_HPP
#define FUNKY_ITERABLES_MAP_HPP

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace funky {
    // (A -> B) -> const F<A> & -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> map(const std::function<B(A)> &mapper, const F<A> &source);

    // (const A & -> B) -> const F<A> & -> F<B>
    template <template <typename...> typename F, typename A, typename B>
    F<B> map(const std::function<B(const A &)> &mapper, const F<A> &source);

    // (char -> char) -> const std::string & -> std::string
    std::string map(const std::function<char(char)> &mapper, const std::string &source);

    // (const A & -> const B & -> C) -> const std::map<A,B> & -> std::vector<C>
    template <typename A, typename B, typename C>
    std::vector<C> map(const std::function<C(const A &, const B &)> &mapper, const std::map<A, B> &source);
}

#endif
