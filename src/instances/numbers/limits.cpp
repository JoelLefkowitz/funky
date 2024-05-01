#include "limits.hpp"

double functional::clamp_proportion(double x) { return clamp(0.0, x, 1.0); }

double functional::normalise(double x, double min, double max, double scale) { return (x * scale - min) / (max - min); }
