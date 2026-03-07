#include "doctest.h"

import Complex;

TEST_CASE("Complex") {
    Complex a{2, 10};
    Complex b{-34, 43};
    Complex c{12, -3};
    Complex d{24};
    
    SUBCASE("real addition") {
        CHECK(a + 10 == Complex(12, 10));
        CHECK(b + 24 == Complex(-10, 43));
        CHECK(c + (-16) == Complex(-4, -3));
        CHECK(d + 3 == Complex(27));
    }

    SUBCASE("complex addition") {
        CHECK(a + b == Complex(-32, 53));
        CHECK(b + c == Complex(-22, 40));
        CHECK(a + c == Complex(14, 7));
        CHECK(d + a == Complex(26, 10));
    }

    SUBCASE("real substraction") {
        CHECK(a - 10 == Complex(-8, 10));
        CHECK(b - 24 == Complex(-58, 43));
        CHECK(c - (-16) == Complex(28, -3));
        CHECK(d - 3 == Complex(21));
    }

    SUBCASE("complex substraction") {
        CHECK(a - b == Complex(36, -33));
        CHECK(b - c == Complex(-46, 46));
        CHECK(a - c == Complex(-10, 13));
        CHECK(d - a == Complex(22, -10));
    }

    SUBCASE("real multiplication") {
        CHECK(a * 10 == Complex( 20, 100));
        CHECK(b * (-2) == Complex(68, -86));
        CHECK(c * 4 == Complex(48, -12));
        CHECK(d * 3 == Complex(72));
    }

    SUBCASE("complex multiplicarion") {
        CHECK(a * b == Complex(-498, -254));
        CHECK(b * c == Complex(-279, 618));
        CHECK(a * c == Complex(54, 114));
        CHECK(d * a == Complex(48, 240));
    }

    SUBCASE("real division") {
        CHECK(a / 10 == Complex( 0, 1));
        CHECK(b / (-2) == Complex(17, -21));
        CHECK(c / 4 == Complex(3, 0));
        CHECK(d / 3 == Complex(8));
    }

    SUBCASE("complex division") {
        CHECK(a / c == Complex(0, 0));
        CHECK(b / a == Complex(3, 4));
        CHECK(c / b == Complex(0, 0));
        CHECK(d / a == Complex(0, -2));
    }

    SUBCASE("logical") {
        CHECK(a == a);
        CHECK(b == b);
        CHECK(c == c);
        CHECK(d == d);

        CHECK(a != b);
        CHECK(b != c);
        CHECK(c != d);
        CHECK(d != Complex<int>());
    }
}