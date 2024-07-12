#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat buro;
	std::cout << buro << std::endl;
	Bureaucrat buro1("Oleg", 44);
	std::cout << buro1 << std::endl;
	Bureaucrat buro2("Azat", 45);
	std::cout << buro2 << std::endl;

	std::cout << "\n#### CONSTRUCTOR TEST #####" << std::endl;
	Form form001;
	std::cout << form001;

	Form form002("Form#002", 44, 58);
	std::cout << form002;

	Form form003(form002);
	std::cout << form003;
	std::cout << "##########################\n" << std::endl;

	std::cout << "##### EXCEPTION TEST #####" << std::endl;
	try {
		Form form004("Form#004", 158, 2);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "##########################\n" << std::endl;

	std::cout << "####### SIGN TEST ########" << std::endl;
	buro2.signForm(form002);
	std::cout << std::endl;

	buro1.signForm(form002);
	std::cout << form002.getName() << " sign status: " << form002.getIsSigned() << std::endl << std::endl;

	buro1.signForm(form002);
	std::cout << "###########################\n" << std::endl;
}
