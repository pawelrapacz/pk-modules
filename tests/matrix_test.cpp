#include "doctest.h"

import <stdexcept>;
import Matrix;
import <iostream>;

TEST_CASE("Matrix") {
    Matrix zero({
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    });

    Matrix ind({
        { 1, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 }
    });

    Matrix ind2({
        { 2, 0, 0, 0 },
        { 0, 2, 0, 0 },
        { 0, 0, 2, 0 },
        { 0, 0, 0, 2 }
    });

    Matrix m1({
        {  5, 3, -7, -1 },
        { -5, 9,  3,  7 },
        {  2, 3,  4,  2 },
        {  3, 4, 13, .5 }
    });

    Matrix m2({
        { 3, 0, 0, 0 },
        { 0, 8, 6, 0 },
        { 1, 0, 0, 0 },
        { 0, 0, 0, 0 }
    });

    Matrix m3 ({
        {  3, .2, -5 },
        { -7,  8,  6 },
        {  1,  4, -1 },
        {  1,  0,  3 }
    });

    Matrix m4 ({
        {  3, 11,  0 },
        { 13,  8, -2 },
        {  1, -4, -1 },
        { -2,  0,  3 }
    });

    Matrix m5 ({
        {  6, .4,  0 },
        { -5, -8,  6 },
        {  1,  5,  3 }
    });


    SUBCASE("logical operators") {
        CHECK(zero == zero);
        CHECK(ind == ind);
        CHECK(m1 == m1);
        CHECK(m2 == m2);
        CHECK(m3 == m3);
        CHECK(m4 == m4);
        CHECK(m5 == m5);

        CHECK(zero != m1);
        CHECK(zero != ind);
        CHECK(m1 != m2);
        CHECK(zero != m5);
        CHECK(ind != m4);
        CHECK(m4 != m5);
    }

    SUBCASE("addition") {
        CHECK(zero + ind == ind);
        CHECK(zero + m1 == m1);
        CHECK(m1 + (-m1) == Matrix(m1.dim()));
        CHECK(zero + (-zero) == zero);
        CHECK(ind + ind == ind2);
        CHECK(ind + ind + ind == ind + ind2 + zero);

        CHECK(m1 + m2 == Matrix({{ 8,  3, -7, -1},
                                 {-5, 17,  9,  7},
                                 { 3,  3,  4,  2},
                                 { 3,  4, 13, .5}}));

        CHECK(ind + m1 == Matrix({{  6,  3, -7,  -1 },
                                  { -5, 10,  3,   7 },
                                  {  2,  3,  5,   2 },
                                  {  3,  4, 13, 1.5 }}));

        CHECK(m3 + m4 == Matrix({{  6, 11.2, -5},
                                 {  6,   16,  4},
                                 {  2,    0, -2},
                                 { -1,    0,  6}}));

        // invalid
        CHECK_THROWS_WITH_AS(m4 + m5, "The matrices must have the same dimensions.", std::logic_error);
        CHECK_THROWS_WITH_AS(zero + m5, "The matrices must have the same dimensions.", std::logic_error);
        CHECK_THROWS_WITH_AS(zero + m5, "The matrices must have the same dimensions.", std::logic_error);
        CHECK_THROWS_WITH_AS(ind + m3, "The matrices must have the same dimensions.", std::logic_error);
    }

    SUBCASE("substraction") {
        CHECK(zero - ind == -ind);
        CHECK(ind - ind == Matrix(ind.dim()));
        CHECK(m5 - m5 == Matrix(m5.dim()));
        CHECK(m3 - m3 -m3 == -m3);
        CHECK(ind - ind - ind2 == -ind2 - zero);

        CHECK(m1 - m2 == Matrix({{ 2, 3, -7, -1},
                                 {-5, 1, -3,  7},
                                 { 1, 3,  4,  2},
                                 { 3, 4, 13, .5}}));

        CHECK(ind - m1 == Matrix({{ -4, -3,   7,  1 },
                                  {  5, -8,  -3, -7 },
                                  { -2, -3,  -3, -2 },
                                  { -3, -4, -13, .5 }}));

        CHECK(m3 - m4 == Matrix({{   0, -10.8, -5},
                                 { -20,     0,  8},
                                 {   0,     8,  0},
                                 {   3,     0,  0}}));

        // invalid
        CHECK_THROWS_WITH_AS(m4 - m5, "The matrices must have the same dimensions.", std::logic_error);
        CHECK_THROWS_WITH_AS(zero - m5, "The matrices must have the same dimensions.", std::logic_error);
        CHECK_THROWS_WITH_AS(zero - m5, "The matrices must have the same dimensions.", std::logic_error);
        CHECK_THROWS_WITH_AS(ind - m3, "The matrices must have the same dimensions.", std::logic_error);
    }

    SUBCASE("scalar multiplication") {
        CHECK(zero * 4 == zero);
        CHECK(ind * 2 == ind2);
        CHECK(m1 * 2 == m1 + m1);
        CHECK(m5 * 4 == m5 + m5 + m5 + m5);
        CHECK(m3 * 0.5 == m3 - m3 * 0.5);
        CHECK(m1 * 4 == Matrix({{  20, 12, -28, -4},
                                { -20, 36,  12, 28},
                                {   8, 12,  16,  8},
                                {  12, 16,  52,  2}}));


        CHECK(m3 * 3 == Matrix({{   9,  .2 * 3, -15},
                                { -21, 24,  18},
                                {   3, 12,  -3},
                                {   3,  0,   9}}));
    }

    SUBCASE("matrix multiplication") {
        CHECK(zero * zero == zero);
        CHECK(zero * m1 == zero);
        CHECK(ind * zero == zero);
        CHECK(ind * ind == ind);
        CHECK(ind2 * ind == ind2);
        CHECK(m1 * ind == m1);
        CHECK(m2 * ind == m2);

        CHECK(m1 * m2 == Matrix({{   8, 24, 18, 0},
                                 { -12, 72, 54, 0},
                                 {  10, 24, 18, 0},
                                 {  22, 32, 24, 0}}));

        CHECK_THROWS_WITH_AS(m1 * m5, "The number of colums of matrix X must equal to the number of rows of matrix Y.", std::logic_error);
        CHECK_THROWS_WITH_AS(ind * m5, "The number of colums of matrix X must equal to the number of rows of matrix Y.", std::logic_error);
        CHECK_THROWS_WITH_AS(zero * m5, "The number of colums of matrix X must equal to the number of rows of matrix Y.", std::logic_error);
        CHECK_THROWS_WITH_AS(m5 * m4, "The number of colums of matrix X must equal to the number of rows of matrix Y.", std::logic_error);
        CHECK_THROWS_WITH_AS(Matrix(23, 4) * Matrix(12, 30), "The number of colums of matrix X must equal to the number of rows of matrix Y.", std::logic_error);        
    }

    SUBCASE("transposition") {
        zero.transpose();
        auto indD = ind;
        ind.transpose();
        m1.transpose();
        m2.transpose();
        m3.transpose();
        m4.transpose();
        m5.transpose();

        CHECK(zero == zero);
        CHECK(ind == indD);
        
        CHECK(m1 == Matrix({{  5, -5, 2,  3},
                            {  3,  9, 3,  4},
                            { -7,  3, 4, 13},
                            { -1,  7, 2, .5}}));

        CHECK(m2 == Matrix({{ 3, 0, 1, 0},
                            { 0, 8, 0, 0},
                            { 0, 6, 0, 0},
                            { 0, 0, 0, 0}}));

        CHECK(m3 == Matrix({{  3, -7,  1, 1},
                            { .2,  8,  4, 0},
                            { -5,  6, -1, 3}}));
        
        CHECK(m4 == Matrix({{  3, 13,  1, -2},
                            { 11,  8, -4,  0},
                            {  0, -2, -1,  3}}));

        CHECK(m5 == Matrix({{  6, -5, 1},
                            { .4, -8, 5},
                            {  0,  6, 3}}));
    }
}