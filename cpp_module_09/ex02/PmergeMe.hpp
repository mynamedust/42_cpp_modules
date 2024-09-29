#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "iostream"
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <ctime>
#include <iomanip>

#define RED_TEXT "\033[31m"
#define RESET_TEXT "\033[0m"

bool printErrAndReturn(std::string message);

class PmergeMe {
	std::vector<int> _vectorContainer;
	std::deque<int> _dequeContainer;
	clock_t _dataLastUpdateStartTime;
	clock_t _dataLastUpdateEndTime;
	clock_t _vectorLastSortTime;
	clock_t _dequeLastSortTime;

	bool validateArgs(char **args) const;
	bool validateArg(char *arg) const;

	int  binarySearchInsertPositionVector(const std::vector<int>& arr, int value);
	int binarySearchInsertPositionDeque(const std::deque<int>& arr, int value);
	std::vector<int> sortVectorContainer(std::vector<int> arr);
	std::deque<int> sortDequeContainer(std::deque<int> arr);

	double clockToDouble(clock_t start, clock_t end) const;
public:
	PmergeMe();
	PmergeMe(char **args);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	bool updateData(char **args);
	bool sortData();
	void printVector() const;
	void printDeque() const;
	void printSortingTime() const;
	int getVectorSize() const;
};



#endif
