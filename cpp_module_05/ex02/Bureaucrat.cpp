#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150){
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat param constructor called." << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bur) {
	os << (bur.getName().empty() ? "*no_name*" : bur.getName()) << ", bureaucrat grade " << bur.getGrade();
	return os;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::gradeDown() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	} catch  (std::exception& e) {
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because: " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::gradeUp() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::executeForm(const AForm &form) {
	try {
		form.execute(*this);
	} catch (const std::exception& e) {
		std::cout << form.getName() << " executing by " << this->getName() << " failed. " << e.what() << std::endl;
		return;
	}

	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high, try another one.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low, try another one.";
}
