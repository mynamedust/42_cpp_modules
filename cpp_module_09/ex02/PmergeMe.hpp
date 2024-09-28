#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "iostream"
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <ctime>

#define RED_TEXT "\033[31m"
#define RESET_TEXT "\033[0m"

bool printErrAndReturn(std::string message);

class PmergeMe {
	std::vector<int> _vectorContainer;
	std::deque<int> _dequeContainer;
	time_t _dataLastUpdateTime;
	time_t _vectorLastSortTime;
	time_t _dequeLastUpdateTime;

	bool validateArgs(char **args) const;
	bool validateArg(char *arg) const;

	int  binarySearchInsertPosition(const std::vector<int>& arr, int value);
	std::vector<int> sortVectorContainer(std::vector<int> arr);

public:
	PmergeMe();
	PmergeMe(char **args);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	bool updateData(char **args);
	bool sortData();
	void printVector() const;
};



#endif
