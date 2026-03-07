#include <iostream>
#include <iomanip>

import Complex;

int main() {
    Complex<double> a{1.0, 2.3};
    Complex<double> b = 6.28;
    auto c = a / b;

    std::cout << std::fixed << std::setprecision(17);
    std::cout << "hello world\n" << 0.1f+0.2f << std::endl;
    return 0;
}