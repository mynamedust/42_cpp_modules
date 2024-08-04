#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>

int compareDates(int year1, int month1, int day1, int year2, int month2, int day2);
void getCurrentDate(int &year, int &month, int &day);

class BitcoinExchange {
	std::map<std::string, float> _exchangeData;
public:
	BitcoinExchange();
	BitcoinExchange(std::string dataFileName);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool validateDataFile(std::string dataFileName) const;
	bool validateDataLine(std::string dataLine) const;
	bool validateInputFile(std::string inputFileName) const;
	bool validateDateString(std::string date) const;
	bool validateValueString(std::string value) const;

	void updateDataFromFile(std::string dataFileName);
	void printExchange(std::string inputFileName) const;
	float getValueByDate(std::string exchangeDate) const;
};



#endif
