#include "numbers.tpp"
#include "strings.hpp"
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

double funky::fractional(double x) {
    double integral = 0;
    return std::modf(x, &integral);
}

double funky::round(double x, size_t dps) {
    auto scale = std::pow(10, dps);
    return std::round(x * scale) / scale;
}

int funky::sign(int n) {
    if (n == 0) {
        return 0;
    }

    return n > 0 ? 1 : -1;
}

int funky::order(double n) {
    if (n > 0) {
        return static_cast<int>(std::floor(std::log10(n)));
    };

    return 0;
}

double funky::proportion(double x) {
    return clamp(0.0, x, 1.0);
}

double funky::normalise(double x, double min, double max, double scale) {
    return (x * scale - min) / (max - min);
}

bool funky::is_factor(int divisor, int dividend) {
    return dividend % divisor == 0;
}

bool funky::has_factor(int dividend, int divisor) {
    return is_factor(divisor, dividend);
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

std::string funky::unit(double n, const std::string &metric) {
    auto magnitude = order(std::abs(n));

    if (magnitude == 0) {
        return metric;
    }

    auto index   = magnitude / 3 + 5;
    auto prefix  = magnitude > 0 ? "⋅" : "÷";
    auto operand = std::pow(10, std::abs(magnitude) % 3);

    std::vector<std::string> named({"f", "p", "n", "μ", "m", "", "k", "M", "G", "T", "P"});

    auto symbol = index >= 0 && index < named.size() ? named.at(index) : "";

    auto trimmed = std::to_string(operand);
    trimmed.erase(trimmed.find_last_not_of('0') + 1, std::string::npos);
    trimmed.erase(trimmed.find_last_not_of('.') + 1, std::string::npos);

    auto prefixed = join({prefix, trimmed, symbol}, "");
    return (operand == 1 ? symbol : prefixed) + metric;
}
