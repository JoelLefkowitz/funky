#ifndef FUNKY_IMPLEMENTATIONS_NUMBERS_DIVISION_HPP
#define FUNKY_IMPLEMENTATIONS_NUMBERS_DIVISION_HPP

#include <cstddef>

namespace funky {
    bool factor(int dividend, int divisor);

    double ratio(size_t dividend, double divisor);
    double ratio(double dividend, size_t divisor);
    double ratio(size_t dividend, size_t divisor);
} // namespace functional

#endif
