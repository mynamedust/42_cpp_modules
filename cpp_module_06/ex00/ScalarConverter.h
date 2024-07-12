#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <ostream>

typedef struct s_literal {
	bool isImpossible;
	char c;
	float f;
	double d;
	int i;
} literal;

class ScalarConverter {
	static const char *pseudof[3];
	static const char *pseudod[3];

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter& other);

	static bool validateLiteral(std::string s);
	static int getType(std::string s);
	static literal parseString(int type, const std::string &s);
	static void printLiteral(literal s);

	static bool checkChar(std::string s);
	static bool checkInt(std::string s);
	static bool checkFloat(std::string s);
	static bool checkDouble(std::string s);
	static bool checkPseudof(std::string s);
	static bool checkPseudod(std::string s);

	static literal castFromChar(std::string s);
	static literal castFromFloat(std::string s);
	static literal castFromDouble(std::string s);
	static literal castFromInt(std::string s);
	static literal castFromPseudof(std::string s);
	static literal castFromPreusod(std::string s);

public:
	enum type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDOF,
		PSEUDOD
	};

	static void convert(std::string literal);
};



#endif
