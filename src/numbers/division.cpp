#include "division.hpp"

bool funky::factor(int dividend, int divisor) {
    return dividend % divisor == 0;
}

double funky::ratio(size_t dividend, double divisor) {
    auto numerator = static_cast<double>(dividend);
    return numerator / divisor;
}

double funky::ratio(double dividend, size_t divisor) {
    auto denominator = static_cast<double>(divisor);
    return dividend / denominator;
}

double funky::ratio(size_t dividend, size_t divisor) {
    auto numerator   = static_cast<double>(dividend);
    auto denominator = static_cast<double>(divisor);
    return numerator / denominator;
}
