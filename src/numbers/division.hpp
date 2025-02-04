#ifndef FUNKY_NUMBERS_DIVISION_HPP
#define FUNKY_NUMBERS_DIVISION_HPP

#include <cstddef>

namespace funky {
    // factor ≔ int → int → bool
    bool factor(int dividend, int divisor);

    // ratio ≔ size_t → double → double
    double ratio(size_t dividend, double divisor);

    // ratio ≔ double → size_t → double
    double ratio(double dividend, size_t divisor);

    // ratio ≔ size_t → size_t → double
    double ratio(size_t dividend, size_t divisor);
}

#endif
