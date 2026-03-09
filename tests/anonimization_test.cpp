#include "doctest.h"

import Anonimization;
import <iostream>;

TEST_CASE("email anonimization") {
    CHECK(mask_email("example@mail.com") == "ex*****@mail.com");
    CHECK(mask_email("ex@mail.com") == "**@mail.com");
    CHECK(mask_email("mail@polsl.pl") == "m***@polsl.pl");
}

TEST_CASE("phone number anonimization") {
    CHECK(mask_phone("123456789") == "******789");
    CHECK(mask_phone("+48123456789") == "+48******789");
    CHECK(mask_phone("+48 123456789") == "+48 ******789");
}

TEST_CASE("name anonimization") {
    CHECK(mask_name("John") == "J***");
    CHECK(mask_name("Michael") == "Mi*****");
    CHECK(mask_name("Smith") == "S****");
    CHECK(mask_name("Donald") == "Do****");
}

TEST_CASE("auto anonimimization") {
    CHECK(autoAnonimization("Jan Jan 666777888 Grazyna Te asd2 123456789 fdsa Henryk Sienkiewicz Robert Mak�owicz fsdfdsa asdfasdfsd") == "J** J** ******888 Gr***** ** asd2 ******789 fdsa He**** Si********* Ro**** Ma********* fsdfdsa asdfasdfsd ");
}