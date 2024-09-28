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
	printVector();
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

	for (int i = 0; args[i]; i++) {
		str = args[i];
		std::stringstream stream(str);

		while(getline(stream, token, ' ')) {
			num = std::atoi(token.c_str());

			// Проверка на дубликаты
			if (nums.find(num) != nums.end()) {
				return printErrAndReturn("duplicate in array");
			}

			_vectorContainer.push_back(num);
			_dequeContainer.push_back(num);
			nums.insert(num);
		}
	}
	// TODO:проверку на дубликаты
	if (_vectorContainer.size() < 2)
		return printErrAndReturn("not enough numbers, must be 2 or more");
	return true;
}

bool PmergeMe::sortData() {
	if (_vectorContainer.empty())
		return printErrAndReturn("sortVectorContainer: empty array passed.");

	_vectorContainer = sortVectorContainer(_vectorContainer);
	if (_vectorContainer.empty())
		return printErrAndReturn("vector sort failed");
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
		sorted.insert(sorted.begin() + binarySearchInsertPosition(sorted, pairs[i][0]), pairs[i][0]);
	}
	if (remainder > -1)
		sorted.insert(sorted.begin() + binarySearchInsertPosition(sorted, remainder), remainder);

	return sorted;
}

int PmergeMe::binarySearchInsertPosition(const std::vector<int>& arr, int value) {
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
	std::cout << "Vector: ";
	for (size_t i = 0; i < _vectorContainer.size(); ++i) {
		std::cout << _vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}


