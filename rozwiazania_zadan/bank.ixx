module;
#include<vector>
#include<iostream>
export module bank;
export import :operation;

export class bank {
	std::string name;
	std::string surname;
	unsigned acc_nr;
	int balance;
	unsigned pin;
	std::vector<operation> operations;
public:
	bank(){}
	bank(std::string _name,std::string _surname,unsigned _acc_nr, int _balance,unsigned _pin):name(_name),surname(_surname), acc_nr(_acc_nr), balance(_balance), pin(_pin) {}
	void transfer(int sum,unsigned _pin) {
		if (_pin == pin) {
			balance += sum;
			operations.push_back(operation(sum));
			std::cout << "account of: " << name << " " << surname << std::endl;
			operations[operations.size() - 1].print_operation();
			std::cout << "balance after operation: " <<balance <<std::endl;
		}
		else {
			std::cout << "incorrect pin cant do operation" << std::endl;
		}
	}
	void check_balance(unsigned _pin) {
		if (_pin == pin) {
			std::cout << "balance of: " << name<<" "<<surname<< std::endl;
			std::cout << "balance: " << balance << std::endl;
		}
		else
			std::cout << "incorrect pin cant check balance" << std::endl;
		
	}
	void printOperations(unsigned _pin) {
		if (_pin == pin) {
			std::cout << "operations of: " << name << " " << surname << std::endl;
			for (int i = 0;i < operations.size();i++) {
				operations[i].print_operation();
				std::cout<<std::endl;
			}
		}
		else
			std::cout << "incorrect pin cant check operations" << std::endl;
		
	}
};