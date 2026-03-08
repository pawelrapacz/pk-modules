#include <iostream>
#include <iomanip>

import Complex;

int main() {
    Complex<double> a{1.0, 2.3};
    Complex<double> b = 6.28;
    auto c = a / b;

    std::cout << std::fixed << std::setprecision(17);
    std::cout << "hello world\n" << 0.1f+0.2f << std::endl;
    
    my::time t;
	t.printZULU();
	t.printGMT();
	t.printLocal();
	std::cout << std::endl;
	std::cout << std::endl;
	
	my::time t2(1644,9,12,8,32,42);
	t2.printZULU();
	t2.printGMT();
	t2.printLocal();
	
	std::cout << anonymize_email("testowy.mail@enter.pl") << std::endl;
	std::cout << anonymize_name("test test") << std::endl;
	std::cout << anonymize_phone_number("123344555") << std::endl;
	std::cout << autoAnonimization("Jan Jan 666777888 Grazyna Te asd2 123456789 fdsa Henryk Sienkiewicz Robert Mak³owicz fsdfdsa asdfasdfsd") << std::endl;
    return 0;
}
