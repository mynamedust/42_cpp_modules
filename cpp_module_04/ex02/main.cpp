#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>


void test1()
{
	std::cout << "-------Constructors test-------" << std::endl;
	Animal *animals[6];
	for (int i = 0; i < 6; i++) {
		if (i < 3)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << "----------Brain test-----------" << std::endl;
	std::ostringstream oss;
	for (int i = 0; i <= 100; i++) {
		oss << i;
		animals[2]->getBrain()->addIdea("idea #" + oss.str());
		oss.clear();
		oss.str("");
	}
	std::cout << animals[2]->getBrain()->getIdea(0) << std::endl;
	std::cout << animals[2]->getBrain()->getIdea(100) << std::endl;
	std::cout << animals[2]->getBrain()->getIdea(99) << std::endl;
	std::cout << "----------Leaks test----------" << std::endl;
	for (int i = 0; i < 6; i++)
		delete animals[i];
}

int main() {
	test1();
	system("leaks aclass");
}

