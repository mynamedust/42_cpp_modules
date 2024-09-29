#include "PmergeMe.hpp"

bool printErrAndReturn(std::string message) {
	std::cerr << RED_TEXT << "error: " << message << RESET_TEXT << std::endl;
	return false;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printErrAndReturn("invalid argument count, should be > 1");
		return 1;
	}

	PmergeMe sorter(++argv);
	if (sorter.getVectorSize() == 0)
		return 1;

	std::cout << "Before: ";
	sorter.printVector();
	if (!sorter.sortData()) {
		printErrAndReturn("sort failed.");
		return 1;
	}

	std::cout << "After: ";
	sorter.printDeque();
	sorter.printSortingTime();

	return 0;
}

