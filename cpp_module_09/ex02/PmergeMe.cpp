#include "PmergeMe.hpp"

bool PmergeMe::validateArg(char *arg) const{
	if (std::strlen(arg) < 1)
		return printErrAndReturn("invalid argument size, should be >= 1.");
	if (isspace(arg[0]))
		return printErrAndReturn(("invalid argument: the argument must not start with a space."));

	bool spaceFlag = false;

	for (int i = 0; arg[i]; i++) {
		if (isspace(arg[i])) {
			if (spaceFlag)
				return printErrAndReturn("consecutive spaces are not allowed.");
			spaceFlag = true;
		} else
			spaceFlag = false;
		if (!isspace(arg[i]) && !isdigit(arg[i]))
			return printErrAndReturn("invalid argument: should use only digits or space/tabs.");
	}
	return true;
}


bool PmergeMe::validateArgs(char **args) const{
	for (int i = 0; args[i]; i++) {
		if (!validateArg(args[i]))
			return false;
	}
	return true;
}

PmergeMe::PmergeMe() {
	std::cout << "info: empty sorter initialized." << std::endl;
}

PmergeMe::PmergeMe(char **args) {
	if (!validateArgs(args)) {
		printErrAndReturn("arguments validation failed.");
		return;
	}

	if (!updateData(args)) {
		printErrAndReturn("data update failed.");
		return;
	}
	std::cout << "info: new sorter initialized with " << _vectorContainer.size() << " numbers." << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << "info: sorter deleted." << std::endl;
}



bool PmergeMe::updateData(char **args) {
	std::string str;
	std::string token;
	std::vector<std::string> result;
	std::set<int> nums;
	int num;

	_dataLastUpdateStartTime = clock();
	for (int i = 0; args[i]; i++) {
		str = args[i];
		std::stringstream stream(str);

		while(getline(stream, token, ' ')) {
			num = std::atoi(token.c_str());

			// Проверка на дубликаты
			if (nums.find(num) != nums.end()) {
				_vectorContainer.erase(_vectorContainer.begin(), _vectorContainer.end());
				_dequeContainer.erase(_dequeContainer.begin(), _dequeContainer.end());
				return printErrAndReturn("duplicate in array");
			}

			_vectorContainer.push_back(num);
			_dequeContainer.push_back(num);
			nums.insert(num);
		}
	}

	if (_vectorContainer.size() < 2)
		return printErrAndReturn("not enough numbers, must be 2 or more");

	_dataLastUpdateEndTime = clock();
	return true;
}

bool PmergeMe::sortData() {
	if (_vectorContainer.empty() || _dequeContainer.empty())
		return printErrAndReturn("empty array passed.");

	_vectorContainer = sortVectorContainer(_vectorContainer);
	if (_vectorContainer.empty())
		return printErrAndReturn("vector sort failed");
	_vectorLastSortTime = clock();

	_dequeContainer = sortDequeContainer(_dequeContainer);
	if (_dequeContainer.empty())
		return printErrAndReturn("deque sort failed");
	_dequeLastSortTime = clock();
	return true;
}


std::vector<int> PmergeMe::sortVectorContainer(std::vector<int> arr) {
	std::vector<int> sorted;
	std::vector<std::vector<int> > pairs;
	int remainder = -1;

	if (arr.empty())
		return sorted;

	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it += 2) {
		if (it + 1 == arr.end()) {
			remainder = *it;
			break;
		}
		std::vector<int> pair;
		pair.push_back(*it);

		if (*(it + 1) > *it)
			pair.push_back(*(it + 1));
		else
			pair.insert(pair.begin(), *(it + 1));
		pairs.push_back(pair);
		sorted.push_back(pair[1]);
	}

	sorted = sortVectorContainer(sorted);
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i][1] == sorted[0]) {
			sorted.insert(sorted.begin(), pairs[i][0]);
			pairs.erase(pairs.begin() + i);
			break;
		}
	}

	for (size_t i = 0; i < pairs.size(); i++) {
		sorted.insert(sorted.begin() + binarySearchInsertPositionVector(sorted, pairs[i][0]), pairs[i][0]);
	}
	if (remainder > -1)
		sorted.insert(sorted.begin() + binarySearchInsertPositionVector(sorted, remainder), remainder);

	return sorted;
}

std::deque<int> PmergeMe::sortDequeContainer(std::deque<int> arr) {
	std::deque<int> sorted;
	std::deque<std::deque<int> > pairs;
	int remainder = -1;

	if (arr.empty())
		return sorted;

	for (std::deque<int>::iterator it = arr.begin(); it != arr.end(); it += 2) {
		if (it + 1 == arr.end()) {
			remainder = *it;
			break;
		}
		std::deque<int> pair;
		pair.push_back(*it);

		if (*(it + 1) > *it)
			pair.push_back(*(it + 1));
		else
			pair.push_front(*(it + 1));
		pairs.push_back(pair);
		sorted.push_back(pair[1]);
	}

	sorted = sortDequeContainer(sorted);
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i][1] == sorted[0]) {
			sorted.push_front(pairs[i][0]);
			pairs.erase(pairs.begin() + i);
			break;
		}
	}

	for (size_t i = 0; i < pairs.size(); i++) {
		sorted.insert(sorted.begin() + binarySearchInsertPositionDeque(sorted, pairs[i][0]), pairs[i][0]);
	}
	if (remainder > -1)
		sorted.insert(sorted.begin() + binarySearchInsertPositionDeque(sorted, remainder), remainder);

	return sorted;
}

int PmergeMe::binarySearchInsertPositionVector(const std::vector<int>& arr, int value) {
	int low = 0;
	int high = arr.size();

	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] < value) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}

int PmergeMe::binarySearchInsertPositionDeque(const std::deque<int>& arr, int value) {
	int low = 0;
	int high = arr.size();

	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] < value) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}

void PmergeMe::printVector() const {
	if (_vectorContainer.empty()) {
		return;
	}
	for (size_t i = 0; i < _vectorContainer.size(); ++i) {
		std::cout << _vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque() const {
	if (_dequeContainer.empty()) {
		return;
	}

	for (size_t i = 0; i < _dequeContainer.size(); ++i) {
		std::cout << _dequeContainer[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printSortingTime() const {
	double dataProcessingTime = clockToDouble(_dataLastUpdateStartTime, _dataLastUpdateEndTime);
	double vectorSortTime =  clockToDouble(_dataLastUpdateEndTime, _vectorLastSortTime);
	double dequeSortTime = clockToDouble(_vectorLastSortTime, _dequeLastSortTime);

	std::cout << "Time to process a range of " << _vectorContainer.size() << " elements with std::vector	: " << dataProcessingTime + vectorSortTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeContainer.size() << " elements with std::deque	: " << dataProcessingTime + dequeSortTime << " us" << std::endl;
}

double PmergeMe::clockToDouble(clock_t start, clock_t end) const{
	return double(end - start) / CLOCKS_PER_SEC * 1000000;
}

int PmergeMe::getVectorSize() const {
	return _vectorContainer.size();
}


