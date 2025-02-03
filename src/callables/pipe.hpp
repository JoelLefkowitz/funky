#ifndef FUNKY_CALLABLES_PIPE_HPP
#define FUNKY_CALLABLES_PIPE_HPP

namespace funky {
    // pipe: T → U → auto
    template <typename T, typename... U>
    auto pipe(const T &f, const U &...gs);
}

#endif
