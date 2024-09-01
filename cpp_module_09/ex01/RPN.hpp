#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN {
	std::stack<int> _operands;
	char _operators[4];
	std::string _expression;
public:
	RPN();
	RPN(std::string expression);
	RPN(const RPN& other);
	~RPN();

	RPN& operator=(const RPN& other);

	std::string getExpression() const;
	void updateExpression(std::string& newExpression);
	bool calculateExpression();
	bool calculateOperator(char c);
	bool printResult() const;

	bool errorReturn(std::string err) const;
	void operatorsInit();
	bool findOperator(char c) const;

	class WrongResultCount : public std::exception {
		const char *what() const throw();
	};
};

#endif
