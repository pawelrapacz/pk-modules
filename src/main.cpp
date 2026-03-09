import <iostream>;
import Complex;
import DateFormats;
import Matrix;
import Anonimization;


int main() {
    Complex<double> a{1.0, 2.3};
    Complex<double> b = 6.28;
    auto c = a / b;

	Matrix m1({{1, 2, 3}});
	Matrix m2({{1, 2, 3}});
	m1 + m2;
	if (m1 * 2 == m1 + m2)
		std::cout << "m1 * 2 == m1 + m2\n";
    
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
	
	std::cout << mask_email("testowy.mail@enter.pl") << std::endl;
	std::cout << mask_name("test test") << std::endl;
	std::cout << mask_phone("123344555") << std::endl;
	std::cout << autoAnonimization("Jan Jan 666777888 Grazyna Te asd2 123456789 fdsa Henryk Sienkiewicz Robert Mak�owicz fsdfdsa asdfasdfsd") << std::endl;
    return 0;
}
