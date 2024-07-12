#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "----------Animals test----------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	Cat cat1;
	Cat cat2(cat1);


	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;
	std::cout << "----------Wrong animals test----------" << std::endl;
	const WrongAnimal* w = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	std::cout << w->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	w->makeSound();
	wc->makeSound();

	delete w;
	delete wc;
	return 0;
}

