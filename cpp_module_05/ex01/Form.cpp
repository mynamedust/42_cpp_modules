#include "Form.hpp"

Form::Form() : _name("untitled_form"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
: _name(name), _isSigned(false) , _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "Form param constructor called." << std::endl;
	checkGrade(signGrade, 150);
	checkGrade(executeGrade, 150);
}

Form::Form(const Form& other)
: _name(other._name + "_copy"), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	std::cout << "Form copy constructor called." << std::endl;
	checkGrade(this->_signGrade, 150);
	checkGrade(this->_executeGrade, 150);
}

Form::~Form() {
	std::cout << "Form destructor called." << std::endl;
}

Form &Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

std::string Form::getName() const {
		return _name;
}

bool Form::getIsSigned() const{
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const char *Form::FormAlreadySigned::what() const throw() {
	return "Form already signed.";
}

std::ostream& operator<<(std::ostream &os, const Form& form) {
	os << "---------------------------\n" <<"Form:\n\tname: " << form.getName() << "\n\tsign grade: " << form.getSignGrade() << "\n\texecute grade: " << form.getExecuteGrade() << "\n\tsigned status: "
	<< form.getIsSigned() << "\n---------------------------" << std::endl;
	return os;
}

bool checkGrade(const int grade, int min) {
	if (grade > min)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	return  false;
}

void Form::beSigned(Bureaucrat bur) {
	checkGrade(bur.getGrade(), this->getSignGrade());
	if (this->_isSigned)
		throw Form::FormAlreadySigned();
	this->_isSigned = true;
}