#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	const std::string _name;
	bool  _isSigned;
	const int _signGrade;
	const int _executeGrade;
public:
	Form();
	Form(const std::string& name, const int signGrade, const int executeGrade);
	Form(const Form& other);
	Form &operator=(const Form& other);
	~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(class Bureaucrat bur);

	class GradeTooHighException : public std::exception{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char *what() const throw();
	};

	class FormAlreadySigned : public std::exception{
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const Form& form);

bool checkGrade(const int grade, int min);

#endif
