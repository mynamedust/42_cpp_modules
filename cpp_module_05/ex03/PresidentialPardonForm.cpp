#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "zero_target", 25, 5){
	std::cout << "PresidentialPardonForm constructor called. New form name: " << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", target,25, 5) {
	std::cout << "PresidentialPardonForm param constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :  AForm(other) {
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm " << " destructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	(void)other;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	checkExecute(executor);

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}