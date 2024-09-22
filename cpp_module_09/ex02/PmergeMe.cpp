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

	for (int i = 0; args[i]; i++) {
		str = args[i];
		std::stringstream stream(str);

		while(getline(stream, token, ' ')) {
			_vectorContainer.push_back(std::atoi(token.c_str()));
			_dequeContainer.push_back(std::atoi(token.c_str()));
		}
	}
	return true;
}

void PmergeMe::printVector() const {
	std::cout << "Vector: ";
	for (size_t i = 0; i < _vectorContainer.size(); ++i) {
		std::cout << _vectorContainer[i] << " ";
	}
	std::cout << std::endl;
}


