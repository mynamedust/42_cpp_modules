#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>
#include <cstdlib>

int test1()
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
	std::cout << "----------Copy test-----------" << std::endl;
	Cat cat1;
	for (int i = 0; i <= 100; i++) {
		oss << i;
		cat1.getBrain()->addIdea("idea #" + oss.str());
		oss.clear();
		oss.str("");
	}
	Cat cat2(cat1);
	std::cout << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << cat2.getBrain()->getIdea(100) << std::endl;
	std::cout << cat2.getBrain()->getIdea(99) << std::endl;
	std::cout << "----------Leaks test----------" << std::endl;
	for (int i = 0; i < 6; i++)
		delete animals[i];
	return 0;
}

int test2()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	return 0;
}

int main() {
	test1();
	test2();
	system("leaks brain");
}

