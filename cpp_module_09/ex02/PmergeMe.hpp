#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "iostream"
#include <sstream>
#include <string>
#include <vector>
#include <deque>
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
public:
	PmergeMe();
	PmergeMe(char **args);
	PmergeMe(const PmergeMe& other);
	PmergeMe operator=(const PmergeMe& other);
	~PmergeMe();

	bool validateArgs(char **args) const;
	bool validateArg(char *arg) const;
	bool updateData(char **args);
	void printVector() const;
};



#endif
