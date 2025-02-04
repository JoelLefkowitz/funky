#ifndef FUNKY_NUMBERS_LIMITS_HPP
#define FUNKY_NUMBERS_LIMITS_HPP

namespace funky {
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
}

#endif
