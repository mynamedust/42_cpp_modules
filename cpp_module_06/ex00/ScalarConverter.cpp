#include "ScalarConverter.h"

#include <iomanip>

const char *ScalarConverter::pseudof[3] = {"+inff", "-inff", "nan"};
const char *ScalarConverter::pseudod[3] = {"+inf", "-inf", "nan"};

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
		return (*this);
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string s) {
	if (!validateLiteral(s)) {
		std::cout << "Invalid argument." << std::endl;
		return ;
	}

	const int type = getType(s);
	if (type == -1) {
		std::cout << "Cannot find valid type." << std::endl;
		return ;
	}

	const literal l = parseString(type, s);
	printLiteral(l);
}

bool ScalarConverter::validateLiteral(std::string s) {
	if (s.empty() || s.find_first_of("+-") != s.find_last_of("+-"))
		return false;
	return true;
}


int ScalarConverter::getType(std::string s) {
	if (checkChar(s))
		return CHAR;
	if (checkFloat(s))
		return FLOAT;
	if (checkDouble(s))
		return DOUBLE;
	if (checkInt(s))
		return INT;
	if (checkPseudof(s))
		return PSEUDOF;
	if (checkPseudod(s)) {
		return PSEUDOD;
	}

	return -1;
}

literal ScalarConverter::parseString(const int type, const std::string &s) {
	switch (type) {
		case CHAR:
			return castFromChar(s);
		case FLOAT:
			return castFromFloat(s);
		case DOUBLE:
			return castFromDouble(s);
		case INT:
			return castFromInt(s);
		case PSEUDOF:
			return castFromPseudof(s);
		default:
			return castFromPreusod(s);
	}
}


bool ScalarConverter::checkChar(std::string s) {
	if (s.length() > 1 || isdigit(s.c_str()[0])) {
		return false;
	}
	if (isprint(s.c_str()[0])) {
		return true;
	}

	return false;
}

bool ScalarConverter::checkFloat(std::string s) {
	if (s.find(".") > 0
		&& s.find_first_of(".") == s.find_last_of(".")
		&& s.find("f") == s.length() - 1
		&& s.find_first_of("f") == s.find_last_of("f")
		&& s.find("f") - s.find(".") > 1
		&& s.find_first_not_of("+-0123456789f.") == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::checkDouble(std::string s) {
	if (s.find(".",0) > 0 && s.find(".", 0) < s.length() - 1
		&& s.find_first_of(".") == s.find_last_of(".")
		&& s.find_first_not_of("+-0123456789.") == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::checkInt(std::string s) {
	if (s.find_first_not_of("+-0123456789") == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::checkPseudof(std::string s) {
	for (int i = 0; i < 2; i++) {
		if (s == pseudof[i])
			return true;
	}
	return false;
}

bool ScalarConverter::checkPseudod(std::string s) {
	for (int i = 0; i < 3; i++) {
		if (s == pseudod[i])
			return true;
	}
	return false;
}

literal ScalarConverter::castFromChar(std::string s) {
	literal l;

	l.c = s[0];
	l.f = static_cast<float>(l.c);
	l.d = static_cast<double>(l.c);
	l.i = static_cast<int>(l.c);

	return l;
}

literal ScalarConverter::castFromFloat(std::string s) {
	literal l;
	double tmp;

	tmp = atof(s.c_str());
	if (tmp > std::numeric_limits<float>::max() || tmp < std::numeric_limits<float>::min()) {
		l.isImpossible = true;
		return l;
	}


	l.isImpossible = false;
	l.i = 0;
	l.c = 0;
	l.f = atof(s.c_str());
	l.d = static_cast<double>(l.f);

	if (l.f >= static_cast<float>(std::numeric_limits<char>::min()) && l.f <= static_cast<float>(std::numeric_limits<char>::max()))
		l.c = static_cast<char>(l.f);

	if (l.f >= static_cast<float>(std::numeric_limits<int>::min()) && l.f <= static_cast<float>(std::numeric_limits<int>::max()))
		l.i = static_cast<int>(l.f);

	return l;
}

literal ScalarConverter::castFromDouble(std::string s) {
	literal l;

	l.isImpossible = false;
	l.c = 0;
	l.i = 0;
	l.d = atof(s.c_str());
	l.f = static_cast<float>(l.d);

	if (l.d >= static_cast<double>(std::numeric_limits<char>::min()) && l.d <= static_cast<double>(std::numeric_limits<char>::max()))
		l.c = static_cast<char>(l.d);

	if (l.d >= static_cast<double>(std::numeric_limits<int>::min()) && l.d <= static_cast<double>(std::numeric_limits<int>::max()))
		l.i = static_cast<int>(l.d);

	return l;
}

literal ScalarConverter::castFromInt(std::string s) {
	literal l;
	double tmp;

	tmp = atof(s.c_str());
	if (tmp > INT_MAX || tmp < INT_MIN) {
		l.isImpossible = true;
		return l;
	}

	l.isImpossible = false;
	l.c = 0;
	l.i = atoi(s.c_str());
	l.f = static_cast<float>(l.i);
	l.d = static_cast<double>(l.i);

	if (l.i >= static_cast<int>(std::numeric_limits<char>::min()) && l.i <= static_cast<int>(std::numeric_limits<char>::max()))
		l.c = static_cast<char>(l.i);

	return l;
}

literal ScalarConverter::castFromPseudof(std::string s) {
	literal l;

	l.i = 0;
	l.c = '\0';
	l.f = strtof(s.c_str(), NULL);
	l.d = static_cast<double>(l.f);

	return l;
}

literal ScalarConverter::castFromPreusod(std::string s) {
	literal l;

	l.i = 0;
	l.c = '\0';
	l.d = strtod(s.c_str(), NULL);
	l.f = static_cast<float>(l.d);

	return l;
}

void ScalarConverter::printLiteral(literal s) {
	if (s.isImpossible || (s.c == '\0' && (s.f != 0 || s.d != 0 || s.i != 0)))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(s.c))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << s.c << "'" << std::endl;

	if (s.isImpossible || (s.i == 0 && (s.f != 0 || s.d != 0)))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << s.i << std::endl;

	if (s.isImpossible || (s.f == 0 && (s.i != 0 || s.d != 0)))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << s.f << "f" << std::endl;

	if (s.isImpossible || (s.d == 0 && (s.i != 0 || s.f != 0)))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << s.d << std::endl;
}







