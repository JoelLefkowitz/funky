#ifndef PIPE_HPP
#define PIPE_HPP

namespace functional {
    template <typename T, typename... F>
    auto pipe(const T &x, const F &...fs);
}

#endif
