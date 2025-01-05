#ifndef FUNKY_NUMBERS_DIVISION_HPP
#define FUNKY_NUMBERS_DIVISION_HPP

#include <cstddef>

namespace funky {
    // int -> int -> bool
    bool factor(int dividend, int divisor);

    // size_t -> double -> double
    double ratio(size_t dividend, double divisor);

    // double -> size_t -> double
    double ratio(double dividend, size_t divisor);

    // size_t -> size_t -> double
    double ratio(size_t dividend, size_t divisor);
}

#endif
