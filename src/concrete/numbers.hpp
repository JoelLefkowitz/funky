#ifndef FUNKY_CONCRETE_NUMBERS_HPP
#define FUNKY_CONCRETE_NUMBERS_HPP

#include <cstddef>
#include <string>

namespace funky {
    // fractional ≔ double → double
    double fractional(double x);

    // round ≔ double → size_t → double
    double round(double x, size_t dps);

    // sign ≔ int → int
    int sign(int n);

    // order ≔ double → int
    int order(double n);

    // proportion ≔ double → double
    double proportion(double x);

    // normalise ≔ double → double → double → double → double
    double normalise(double x, double min, double max, double scale);

    // is_factor ≔ int → int → bool
    bool is_factor(int divisor, int dividend);

    // has_factor ≔ int → int → bool
    bool has_factor(int dividend, int divisor);

    // ratio ≔ size_t → double → double
    double ratio(size_t dividend, double divisor);

    // ratio ≔ double → size_t → double
    double ratio(double dividend, size_t divisor);

    // ratio ≔ size_t → size_t → double
    double ratio(size_t dividend, size_t divisor);

    // unit ≔ double → std::string → std::string
    std::string unit(double n, const std::string &metric);

    // bounds ≔ A → A → A → bool
    template <typename A>
    bool bounds(A lower, A x, A higher);

    // includes ≔ A → A → A → bool
    template <typename A>
    bool includes(A lower, A x, A higher);

    // clamp ≔ A → A → A → A
    template <typename A>
    A clamp(A lower, A x, A higher);
}

#endif
