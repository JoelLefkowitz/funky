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

    // between ≔ T → T → T → bool
    template <typename T>
    bool between(T lower, T x, T higher);

    // contains ≔ T → T → T → bool
    template <typename T>
    bool contains(T lower, T x, T higher);

    // clamp ≔ T → T → T → T
    template <typename T>
    T clamp(T lower, T x, T higher);

    // clamp_proportion ≔ double → double
    double clamp_proportion(double x);

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
}

#endif
