#include "Bureaucrat.hpp"

int main() {
	Bureaucrat buro;
	std::cout << buro << std::endl;
	try {
		Bureaucrat buro1("Oleg", 151);
		std::cout << buro1 << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Programm still work." << std::endl;

	try {
		Bureaucrat buro3("David", 150);
		std::cout << buro3 << std::endl;
		buro3.gradeDown();
		std::cout << buro3 << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
