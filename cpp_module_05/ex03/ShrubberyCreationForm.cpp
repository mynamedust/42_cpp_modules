#include "ShrubberyCreationForm.hpp"
#include <sstream>
#include <iomanip>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "zero_target", 145, 137){
	std::cout << "ShrubberyCreationForm constructor called. New form name: " << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", target,145, 137) {
	std::cout << "ShrubberyCreationForm param constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :  AForm(other) {
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << " destructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	(void)other;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	checkExecute(executor);

	std::ofstream outfile (this->getTarget() + "_shrubbery");
	outfile << createNewASCIITree();
	outfile.close();
}

std::string ShrubberyCreationForm::createNewASCIITree() const {
	std::ostringstream ss;

	int cap = 18;
	int wood = 3;
	int woodCup = 2;

	for (int i = 1; i <= cap; i += 2) {
		std::string wsStr((cap - i) / 2, ' ');
		std::string chrStr(i, '*');

		ss << wsStr << chrStr << wsStr << std::endl;
	}

	for (int i = 0; i < woodCup; i++) {
		std::string wsStr((cap - wood) / 2, ' ');
		std::string chrStr(wood, '|');

		ss << wsStr << chrStr << wsStr << std::endl;
	}

	return ss.str();
}




