#include "RobotomyRequestForm.hpp"
#include<unistd.h>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "zero_target", 72, 45) {
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("ShrubberyCreationForm", target,72, 45) {
	std::cout << "RobotomyRequestForm param constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << " destructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	(void)other;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	checkExecute(executor);

	std::srand(std::time(0));
	for (int i = 0; i < 3; i++) {
		std::cout << "*dzzzzzzzzzzzzzzzzzzzzzzzz*" << std::endl;
		sleep(1);
	}

	std::cout << "*woup woup*" << std::endl;
	sleep(1);
	std::cout << "*pr  pr  pr  pr*" << std::endl;
	sleep(1);

	if (std::rand() % 2)
		std::cout << this->getTarget() <<" has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotizing has been failed. Try again." << std::endl;
}