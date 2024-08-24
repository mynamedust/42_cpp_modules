#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "info: empty bitcoin exchanger initialized" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string& dataFileName) {
	std::cout << "info: bitcoin exchanger initialized: data source: " << dataFileName << std::endl;
	updateDataFromFile(dataFileName);
}

BitcoinExchange::~BitcoinExchange() {
	if (!_error.empty())
		std::cerr << RED_TEXT << "error: " << _error << RESET_TEXT << std::endl;
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

void BitcoinExchange::updateDataFromFile(std::string dataFileName) {
	bool status = validateDataAndUpdate(dataFileName);

	if (status) {
		system("clear");
		std::cout << GREEN_TEXT << "info: data file validation passed successful" << RESET_TEXT << std::endl;
	} else
		std::cout << RED_TEXT << "info: data file validation failed" << RESET_TEXT << std::endl;
}


bool BitcoinExchange::validateDataAndUpdate(std::string dataFileName) {
	std::ifstream in;
	std::ostringstream errStream;

	in.open(dataFileName, std::ios::in);
	if (!in.is_open()) {
		in.close();
		return wrapError("data file open failed");
	}

	std::string line;
	if (!getline(in, line) || line != "date,exchange_rate") {
		in.close();
		return wrapError("invalid data file: wrong header");
	}

	for (int i = 2; getline(in, line); i++) {
		if (!validateDataLine(line)) {
			errStream << "line " << i <<": incorrect format";
			in.close();
			return wrapError(errStream.str());
		}

		std::string date = line.substr(0, line.find(','));
		std::string value = line.substr(line.find(',') + 1);

		if (_exchangeData.count(date)) {
			errStream << "line " << i <<": duplicates are forbidden" << std::endl;
			in.close();
			return wrapError(errStream.str());;
		}
		_exchangeData[date] = atof(value.c_str());

		std::cout << "info: line " << i << ": validation passed" << std::endl;
	}
	if (_exchangeData.size() == 0)
		return wrapError("empty data file");

	return true;
}

bool BitcoinExchange::validateDataLine(std::string dataLine) {
	std::istringstream dataStream(dataLine);
	std::string date;
	std::string value;

	if (!getline(dataStream, date, ',') || !getline(dataStream, value))
		return wrapError("empty or incorrect format line");
	if (!validateDateString(date))
		return wrapError("invalid date string");
	if (!validateValueString(value, false))
		return wrapError("invalid value string");

	return true;
}

bool BitcoinExchange::validateDateString(std::string date) {
	std::istringstream dateStream(date);
	std::string year, month, day;
	int numYear, numMonth, numDay;

	if (date.length() != 10)
		return wrapError("wrong lenght");
	if (!getline(dateStream, year, '-') || !getline(dateStream, month, '-') || !getline(dateStream, day))
		return wrapError("string not complete YYYY-MM-DD format");
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return wrapError("string not complete YYYY-MM-DD format");

	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (!isdigit(date[i]))
			return wrapError("date must contain only digits");
	}

	numYear = atoi(year.c_str());
	numMonth = atoi(month.c_str());
	numDay = atoi(day.c_str());

	int currentYear, currentMonth, currentDay;
	getCurrentDate(currentYear, currentMonth, currentDay);

	int bitcoinYear = 2009;
	int bitcoinMonth = 1;
	int bitcoinDay = 2;

	if (compareDates(numYear, numMonth, numDay, bitcoinYear, bitcoinMonth, bitcoinDay) == -1
		|| compareDates(numYear, numMonth, numDay, currentYear, currentMonth, currentDay) == 1)
		return wrapError("the date cannot be earlier than the creation of Bitcoin");

	if (numMonth > 12 || numMonth < 1)
		return wrapError("invalid month format");

	int daysByMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (numMonth > daysByMonth[numMonth - 1] || (numDay > 28 && numMonth == 2 && numYear % 4 != 0))
		return wrapError("invalid day by month");

	return true;
}

bool BitcoinExchange::validateValueString(std::string value, bool isInputValue) {
	std::istringstream inputStream(value);
    float numValue;
    std::string remainder;

	if (!isdigit(value[0]))
		return wrapError("extra characters in the line");
    if (inputStream >> numValue) {
        if (getline(inputStream, remainder))
			return wrapError("extra characters in the line");
        if (numValue < 0)
        	return wrapError("value must be either a float or a positive integer");
    	if (isInputValue && numValue > 1000)
    		return wrapError("input value must be between 0 and 1000");
    	return true;
    }

    return false;
}

bool BitcoinExchange::wrapError(const std::string &newErr) {
	if (_error.empty()) {
		_error = newErr;  // Если ошибки нет, устанавливаем новую ошибку
	} else {
		_error = newErr + ": " + _error;  // Оборачиваем существующую ошибку
	}

	return false;
}

bool BitcoinExchange::exchangeInput(std::string inputFile) {
	std::ifstream in;
	std::ostringstream errStream;

	in.open(inputFile, std::ios::in);
	if (!in.is_open()) {
		in.close();
		return wrapError("input file open failed");
	}

	std::string line;
	if (!getline(in, line) || line != "date | value") {
		in.close();
		return wrapError("invalid input file: wrong header");
	}

	for (int i = 2; getline(in, line); i++) {
		if (!validateInputLine(line)) {
			errStream.str("");
			errStream << "line " << i;
			wrapError(errStream.str());
			std::cerr << RED_TEXT << "error: " << _error << RESET_TEXT << std::endl;
			_error.clear();
			continue;
		}

		if (!exchangeLine(line)) {
			std::cerr << RED_TEXT << "error: " << _error << RESET_TEXT << std::endl;
			_error.clear();
		}
	}
	in.close();

	return true;
}

bool BitcoinExchange::exchangeLine(std::string line) {
	std::string date;
	std::string value;
	std::string delimiter = " | ";
	float exchangeRate = -1;

	size_t delimiterPos = line.find(delimiter);
	if (delimiterPos == std::string::npos)
		return wrapError("incorrect format: missing delimiter");

	date = line.substr(0, delimiterPos);
	value = line.substr(delimiterPos + delimiter.length());

	if (_exchangeData.count(date))
		exchangeRate = _exchangeData[date];
	else {
		for (std::map<std::string, float>::iterator it = _exchangeData.begin(); it != _exchangeData.end(); it++) {
			if (it->first > date)
				break;
			exchangeRate = it->second;
		}

		if (exchangeRate == -1)
			exchangeRate = _exchangeData.begin()->second;
	}

	std::cout << date << " => " << value << " = " << exchangeRate * atof(value.c_str()) << std::endl;
	return true;
}

bool BitcoinExchange::validateInputLine(std::string line) {
	std::string date;
	std::string value;
	std::string delimiter = " | ";

	size_t delimiterPos = line.find(delimiter);
	if (delimiterPos == std::string::npos)
		return wrapError("incorrect format: missing delimiter");

	date = line.substr(0, delimiterPos);
	value = line.substr(delimiterPos + delimiter.length());

	if (!validateDateString(date))
		return wrapError("invalid date string");

	if (!validateValueString(value, true)) {
		return wrapError("invalid value string");
	}
	return true;
}

std::string BitcoinExchange::getError() const {
	return this->_error;
}

