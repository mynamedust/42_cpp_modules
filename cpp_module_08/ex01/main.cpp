#include <iostream>
#include "Span.hpp"

int main() {
	try {
		// Test 1: Basic functionality
		Span sp1(5);
		sp1.addNubmer(5);
		sp1.addNubmer(3);
		sp1.addNubmer(17);
		sp1.addNubmer(9);
		sp1.addNubmer(11);

		std::cout << "Longest span: " << sp1.longestSpan() << std::endl; // Expected: 14 (17 - 3)
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl; // Expected: 2 (5 - 3 or 11 - 9)

		// Test 2: Exception handling for overflow
		try {
			sp1.addNubmer(6);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl; // Expected: "Span already filled."
		}

		// Test 3: Exception handling for not enough elements
		Span sp2(3);
		try {
			std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl; // Expected: "Not enough elements. Need minimum 2."
		}

		sp2.addNubmer(1);
		try {
			std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl; // Expected: "Not enough elements. Need minimum 2."
		}

		// Test 4: Large number of elements
		Span sp3(10000);
		for (int i = 0; i < 10000; ++i) {
			sp3.addNubmer(i);
		}
		std::cout << "Longest span in 10,000 elements: " << sp3.longestSpan() << std::endl; // Expected: 9999
		std::cout << "Shortest span in 10,000 elements: " << sp3.shortestSpan() << std::endl; // Expected: 1

	} catch (const std::exception &e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}