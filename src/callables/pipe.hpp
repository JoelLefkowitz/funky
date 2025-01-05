#ifndef FUNKY_CALLABLES_PIPE_HPP
#define FUNKY_CALLABLES_PIPE_HPP

namespace funky {
    // const T & -> const U & -> auto
    template <typename T, typename... U>
    auto pipe(const T &f, const U&...gs);
}

#endif
