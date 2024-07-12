#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

int main() {
	Array<int> arr1(5);
	for (unsigned int i = 0; i < arr1.size(); i++) {
		arr1[i] = i;
	}

	Array<int> arr2(5);
	for (unsigned int i = 0; i < arr2.size(); i++) {
		arr2[i] = i * 2;
	}

	Array<int> arr3(arr1);
	Array<int> arr4;
	arr4 = arr2;

	std::cout << std::endl;
	try {
		std::cout << arr4[100] << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}