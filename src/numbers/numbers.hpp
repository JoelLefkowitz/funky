#ifndef FUNKY_NUMBERS_NUMBERS_HPP
#define FUNKY_NUMBERS_NUMBERS_HPP

#include <cstddef>
#include <string>

namespace funky {
    // frac ≔ double → double
    double frac(double x);

    // round ≔ double → size_t → double
    double round(double x, size_t dps);

    // sign ≔ int → int
    int sign(int n);

    // order ≔ double → int
    int order(double n);

    // units_prefix ≔ double → std::string
    std::string units_prefix(double n);
}

#endif
