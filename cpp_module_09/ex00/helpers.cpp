#include <ctime>
#include <iostream>

int compareDates(int year1, int month1, int day1, int year2, int month2, int day2) {
	if (year1 < year2) {
		return -1;
	} else if (year1 > year2) {
		return 1;
	} else {
		if (month1 < month2) {
			return -1;
		} else if (month1 > month2) {
			return 1;
		} else {
			if (day1 < day2) {
				return -1;
			} else if (day1 > day2) {
				return 1;
			} else {
				return 0;
			}
		}
	}
}

void getCurrentDate(int &year, int &month, int &day) {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	day = now->tm_mday;
}

void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
