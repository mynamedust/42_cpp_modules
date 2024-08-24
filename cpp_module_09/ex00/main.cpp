#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2 ) {
		std::cerr << RED_TEXT << "error: wrong number of arguments" << RESET_TEXT << std::endl;
		return 1;
	}

	std::string fileName = "data.csv";
	BitcoinExchange exchanger(fileName);
	if (!exchanger.getError().empty())
		return 1;
	exchanger.exchangeInput(argv[1]);
}
