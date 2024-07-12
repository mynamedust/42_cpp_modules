#include "iter.hpp"

int main() {
	std::cout << "number array test: " << std::endl;
	int numArr[] = {1,2313,4324,53234,1231};
	iter(numArr, 5, print);

	std::cout << std::endl << "string array test: " << std::endl;
	std::string stringArr[] = {"first", "second", "chiwawa", "badumtss"};
	iter(stringArr, 4, print);

	std::cout << std::endl << "bool array test: " << std::endl;
	bool boolArr[] = {false, true, false, true, true, true, false};
	iter(boolArr, 7, print);
}
