#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "info: empty bitcoin exchanger initialized" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string dataFileName) {
	updateDataFromFile(dataFileName);
	std::cout << "info: bitcoin exchanger initialized: data source: " << dataFileName << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "info: bitcoin exchanger deleted" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeData(other._exchangeData) {
	std::cout << "info: bitcoin exchanger initialized: data source: copy" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_exchangeData = other._exchangeData;
	}
	return *this;
}

bool BitcoinExchange::validateDataFile(std::string dataFileName) const {
	std::ifstream in;

	in.open(dataFileName, std::ios::in);
	if (!in.is_open()) {
		std::cerr << "error: data file open failed" << std::endl;
		in.close();
		return false;
	}

	std::string line;
	if (getline(in, line) != "date,exchange_rate") {
		std::cerr << "error: invalid data file" << std::endl;
		in.close();
		return false;
	}

	std::set<std::string> dates;

	for (int i = 2; getline(in, line); i++) {
		if (!validateDataLine(line)) {
			std::cerr << "error: line: " << i <<": invalid data file: incorrect format" << std::endl;
			in.close();
			return false;
		}

		if (dates.find(line) != dates.end()) {
			std::cerr << "error: line: " << i <<": invalid data file: duplicates are forbidden" << std::endl;
			in.close();
			return false;
		}

		std::cout << "info: line: " << i << ": validation passed" << std::endl;
		dates.insert(line);
	}

	std::cout << "info: data file passed validation" << std::endl;
	return true;
}

bool BitcoinExchange::validateDataLine(std::string dataLine) const {
	std::istringstream dataStream(dataLine);
	std::string date;
	std::string value;

	if (!getline(dataStream, date, ',') || !getline(dataStream, value))
		return false;
	if (!validateDateString(date))
		return false;
	if (!validateValueString(value))
		return false;

	return true;
}

bool BitcoinExchange::validateDateString(std::string date) const {
	std::istringstream dateStream(date);
	std::string year, month, day;
	int numYear, numMonth, numDay;

	if (date.length() != 10)
		return false;
	if (!getline(dateStream, year, '-') || !getline(dateStream, month, '-') || !getline(dateStream, day))
		return false;
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return false;

	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (!isdigit(date[i]))
			return false;
	}

	numYear = atoi(year.c_str());
	numMonth = atoi(month.c_str());
	numDay = atoi(day.c_str());

	int currentYear, currentMonth, currentDay;
	getCurrentDate(currentYear, currentMonth, currentDay);

	int bitcoinYear = 2009;
	int bitcoinMonth = 1;
	int bitcoinDay = 3;

	if (compareDates(numYear, numMonth, numDay, bitcoinYear, bitcoinMonth, bitcoinDay) == -1
		|| compareDates(numYear, numMonth, numDay, currentYear, currentMonth, currentDay == 1))
		return false;


	return true;
}

bool BitcoinExchange::validateValueString(std::string value) const {
	std::string::const_iterator it = value.begin();

	while (it != value.end()) {
		if (!std::isdigit(*it))
			return false;
		++it;
	}

	if (value > "1000" || value[0] == '-')
		return false;

	return true;
}
