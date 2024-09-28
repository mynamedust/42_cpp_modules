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
	sorter.sortData();
	sorter.printVector();

	// std::cout << "Before: " << sorter.printVector() << std::endl;
	// if (!sorter.sortVector()) {
	// 	printErrAndReturn("vector sort failed.")
	// 	return 1;
	// }
	// if (!sorter.SortDeque()) {
	// 	printErrAndReturn("deque sort failed.");
	// 	return 1;
	// }
	//
	// std::cout << "After: " << sorter.printVector() << std::endl;
	// sorter.printLastSortTime();

	return 0;
}

