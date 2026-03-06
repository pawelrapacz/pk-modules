import Complex;
import <iostream>;

int main() {
    Complex<double> a{1.0, 2.3};
    Complex<double> b = 1.234;
    auto c = a / b;
    return 0;
}