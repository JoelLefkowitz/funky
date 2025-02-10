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

    // factor ≔ int → int → bool
    bool factor(int dividend, int divisor);

    // ratio ≔ size_t → double → double
    double ratio(size_t dividend, double divisor);

    // ratio ≔ double → size_t → double
    double ratio(double dividend, size_t divisor);

    // ratio ≔ size_t → size_t → double
    double ratio(size_t dividend, size_t divisor);

    // unit ≔ double → std::string → std::string
    std::string unit(double n, const std::string &metric);

    // between ≔ A → A → A → bool
    template <typename A>
    bool between(A lower, A x, A higher);

    // included ≔ A → A → A → bool
    template <typename A>
    bool included(A lower, A x, A higher);

    // clamp ≔ A → A → A → A
    template <typename A>
    A clamp(A lower, A x, A higher);
}

#endif
