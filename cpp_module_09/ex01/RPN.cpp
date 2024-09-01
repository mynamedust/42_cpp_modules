#include "RPN.hpp"

RPN::RPN() {
	operatorsInit();
}

RPN::RPN(std::string expression) : _expression(expression) {
	operatorsInit();
}

RPN::RPN(const RPN &other) : _expression(other.getExpression()){
	operatorsInit();
}

RPN &RPN::operator=(const RPN &other) {
	operatorsInit();
	if (this != &other) {
		this->_expression = other._expression;
	}
	return *this;
}

RPN::~RPN() {}

std::string RPN::getExpression() const {
	return _expression;
}

void RPN::updateExpression(std::string& newExpression) {
	_expression = newExpression;
}

bool RPN::errorReturn(std::string err) const {
	std::cerr << err << std::endl;
	return false;
}

bool RPN::calculateExpression() {
	if (_expression.size() == 0)
		return errorReturn("error: passed empty expression");

	std::stack<char> operatorStack; // Создаем пустой стек

	operatorStack.push('+');
	operatorStack.push('-');
	operatorStack.push('*');
	operatorStack.push('/');
	bool spaceFlag = false;

	for (std::string::iterator it = _expression.begin(); it != _expression.end(); it++) {
		if (spaceFlag != (*it == ' '))
			return errorReturn("error: wrong expression format: space position");

		spaceFlag = !spaceFlag;
		if (*it == ' ')
			continue;

		if (isdigit(*it)) {
			_operands.push(atoi(&(*it)));
			continue;
		}

		if (findOperator(*it)) {
			if (!calculateOperator(*it))
				return false;
			continue;
		}

		return errorReturn("error: wrong expression format: wrong character");
	}

	if (!spaceFlag)
		return errorReturn("error: wrong expression format: space at the end");

	return true;
}

void RPN::operatorsInit() {
	_operators[0] = '+';
	_operators[1] = '-';
	_operators[2] = '*';
	_operators[3] = '/';
}

bool RPN::findOperator(char c) const {
	for (int i = 0; i < 4; i++) {
		if (c == _operators[i])
			return true;
	}

	return false;
}

bool RPN::calculateOperator(char c) {
	if (_operands.size() < 2)
		return errorReturn("error: wrong format: expression does not match rpn");

	int a = _operands.top();
	_operands.pop();
	int b = _operands.top();
	_operands.pop();

	switch (c) {
		case '+':
			_operands.push(b + a);
			break;
		case '-':
			_operands.push(b - a);
			break;
		case '*':
			_operands.push(b * a);
			break;
		case '/':
			if (a == 0) {
				return errorReturn("error: division by zero");
			}
			_operands.push(b / a);
			break;
		default:
			return errorReturn("error: unknown operator");
	}

	return true;
}

bool RPN::printResult() const {
	if (_operands.size() != 1)
		return errorReturn("error: wrong result stack size");
	std::cout << _operands.top() << std::endl;
	return true;
}










