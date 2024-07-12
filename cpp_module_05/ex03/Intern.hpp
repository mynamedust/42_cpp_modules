#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"


class Intern {
	AForm *createShrubberyForm(const std::string& target) const;
	AForm *createRobotomyForm(const std::string& target) const;
	AForm *createPresidentialForm(const std::string& target) const;
public:
	Intern();
	Intern(const Intern& other);
	Intern &operator=(const Intern& other);
	~Intern();

	AForm *makeForm(const std::string& formType, const std::string& target) const;
};



#endif
