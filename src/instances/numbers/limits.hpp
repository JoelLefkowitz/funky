#ifndef FUNCTIONAL_INSTANCES_NUMBERS_LIMITS_HPP
#define FUNCTIONAL_INSTANCES_NUMBERS_LIMITS_HPP

namespace functional {
    template <typename T>
    bool between(T lower, T x, T higher);

    template <typename T>
    bool contains(T lower, T x, T higher);

    template <typename T>
    T clamp(T lower, T x, T higher);

    double clamp_proportion(double x);

    double normalise(double x, double min, double max, double scale);
} // namespace functional

#endif
