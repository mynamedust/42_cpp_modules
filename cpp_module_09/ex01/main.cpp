#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2 ) {
		std::cerr << "error: wrong argument count" << std::endl;
		return 1;
	}

	RPN rpn(argv[1]);
	if (!rpn.calculateExpression())
		return 1;
	if (!rpn.printResult())
		return 1;

	return 0;
}