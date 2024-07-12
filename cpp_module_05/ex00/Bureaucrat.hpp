#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	int getGrade() const;
	void gradeUp();
	void gradeDown();
	void signForm() const;

	class GradeTooHighException : public std::exception{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char *what() const throw();
	};

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bur);

#endif
