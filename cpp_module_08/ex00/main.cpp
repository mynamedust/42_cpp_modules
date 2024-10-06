#include "easyfind.hpp"

int main() {
	int arr1[] = {1, 345, 34534, 234, 65, 34};

	std::vector<int> vector1 (arr1, arr1 + sizeof(arr1) / sizeof(int));
	std::list<int> list1 (arr1, arr1 + sizeof(arr1) / sizeof(int));

	try {
		std::cout << "Position: " << easyfind(vector1, 65) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Position: " << easyfind(list1, 234) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what();
	}
	try {
		std::cout << "Position: " << easyfind(list1, 131313) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what();
	}

	return 0;
}
