#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat buro;
	std::cout << buro << std::endl;
	Bureaucrat buro1("Oleg", 138);
	std::cout << buro1 << std::endl;
	Bureaucrat buro2("Azat", 5);
	std::cout << buro2 << std::endl;

	std::cout << "\n############### SIGNING TEST ################" << std::endl;
	ShrubberyCreationForm shrubbery111;
	buro2.signForm(shrubbery111);
	buro1.signForm(shrubbery111);

	RobotomyRequestForm robotomy111("Tony Stark");
	buro1.signForm(robotomy111);
	buro2.signForm(robotomy111);

	PresidentialPardonForm presidential111("Joe Biden");
	buro1.signForm(presidential111);
	buro2.signForm(presidential111);
	std::cout << "\n############### EXECUTE TEST ################" << std::endl;
	buro1.executeForm(shrubbery111);
	buro2.executeForm(shrubbery111);
	buro1.executeForm(robotomy111);
	buro2.executeForm(robotomy111);
	buro1.executeForm(presidential111);
	buro2.executeForm(presidential111);
}
