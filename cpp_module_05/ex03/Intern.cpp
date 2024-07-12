#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &other) {
	(void)other;
	std::cout << "Intern copy constructor called." << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called." << std::endl;
}

AForm *Intern::createShrubberyForm(const std::string& target) const{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string& target) const{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string& target) const{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string& formType, const std::string& target) const{
	std::string formTypes[] = {"shrubbery", "robotomy", "presidential"};
	AForm* (Intern::*formsCreateFuncs[])(const std::string& target) const = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};
	for (int i = 0; i < 3; i++) {
		if (formTypes[i] == formType)
			return (this->*formsCreateFuncs[i])(target);
	}
	std::cout << "Wrong formType. Try another." << std::endl;
	return NULL;
}
