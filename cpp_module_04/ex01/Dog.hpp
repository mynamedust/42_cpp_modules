#ifndef INC_42_CPP_MODULE_04_DOG_HPP
#define INC_42_CPP_MODULE_04_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
private:
	Brain* brain;
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);

	void makeSound() const;
	Brain* getBrain() const;
};

#endif
