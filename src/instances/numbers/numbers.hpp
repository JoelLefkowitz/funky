#ifndef FUNCTIONAL_INSTANCES_NUMBERS_NUMBERS_HPP
#define FUNCTIONAL_INSTANCES_NUMBERS_NUMBERS_HPP

#include <cstddef>
#include <string>

namespace functional {
    double frac(double x);
    double round(double x, size_t dps);

    int sign(int n);
    int order(double n);

    std::string units_prefix(double n);
} // namespace functional

#endif
