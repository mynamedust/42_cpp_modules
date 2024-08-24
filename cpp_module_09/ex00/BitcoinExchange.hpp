#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

int compareDates(int year1, int month1, int day1, int year2, int month2, int day2);
void getCurrentDate(int &year, int &month, int &day);
void clearConsole();

class BitcoinExchange {
	std::map<std::string, float> _exchangeData;
	std::string _error;
public:
	BitcoinExchange();
	BitcoinExchange(std::string& dataFileName);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool validateInputFile(std::string inputFileName);
	bool validateDataAndUpdate(std::string dataFileName);
	void updateDataFromFile(std::string dataFileName);

	bool validateDataLine(std::string dataLine);
	bool validateDateString(std::string date);
	bool validateValueString(std::string value, bool isInputValue);

	bool exchangeInput(std::string inputFile);
	bool exchangeLine(std::string line);
	bool validateInputLine(std::string line);

	bool wrapError(const std::string& err);
	std::string getError() const;
};



#endif
