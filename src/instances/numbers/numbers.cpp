#include "numbers.hpp"
#include "../strings/strings.hpp"
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

double functional::frac(double x) {
    double integral = 0;
    return std::modf(x, &integral);
}

double functional::round(double x, size_t dps) {
    auto scale = std::pow(10, dps);
    return std::round(x * scale) / scale;
}

int functional::sign(int n) {
    if (n == 0) {
        return 0;
    }

    return n > 0 ? 1 : -1;
}

int functional::order(double n) {
    if (n > 0) {
        return static_cast<int>(std::floor(std::log10(n)));
    };

    return 0;
}

std::string functional::units_prefix(double n) {
    auto magnitude = order(std::abs(n));

    if (magnitude == 0) {
        return "";
    }

    auto operand = std::pow(10, std::abs(magnitude) % 3);
    auto prefix  = magnitude > 0 ? "⋅" : "÷";

    std::vector<std::string> named = {"f", "p", "n", "μ", "m", "", "k", "M", "G", "T", "P"};

    auto index  = (magnitude / 3) + 5;
    auto symbol = index >= 0 && index < named.size() ? named.at(index) : "";

    auto trimmed = std::to_string(operand);
    trimmed.erase(trimmed.find_last_not_of('0') + 1, std::string::npos);
    trimmed.erase(trimmed.find_last_not_of('.') + 1, std::string::npos);

    return operand == 1 ? symbol : join({prefix, trimmed, symbol}, "");
}
