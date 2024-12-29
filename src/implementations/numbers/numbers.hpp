#ifndef FUNKY_IMPLEMENTATIONS_NUMBERS_NUMBERS_HPP
#define FUNKY_IMPLEMENTATIONS_NUMBERS_NUMBERS_HPP

#include <cstddef>
#include <string>

namespace funky {
    double frac(double x);
    double round(double x, size_t dps);

    int sign(int n);
    int order(double n);

    std::string units_prefix(double n);
} // namespace functional

#endif
