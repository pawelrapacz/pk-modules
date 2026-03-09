module;

#include <utility>
#include <cmath>

export module mathh:quadratic;
import Complex;

std::pair<Complex<double>, Complex<double>>
quadratic(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    Complex<double> sqrt_d = d;

    if (d < 0) {
        sqrt_d = {0, std::sqrt(std::abs(d))};
    }

    auto z1 = (-b + sqrt_d) / (2 * a);
    auto z2 = (-b - sqrt_d) / (2 * a);
    return {z1, z2};
}