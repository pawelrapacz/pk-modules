export module bank:operation;
import DateFormats;
export class operation {
	my::time optime;
	int sum;
public:
	operation(int _sum):optime(my::time()), sum(_sum){}
	void print_operation() {
		std::cout << "operation time: ";
		optime.printGMT();
		std::cout << "operation sum: "<<sum<<std::endl;
	}
};