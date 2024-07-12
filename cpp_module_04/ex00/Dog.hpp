#ifndef INC_42_CPP_MODULE_04_DOG_HPP
#define INC_42_CPP_MODULE_04_DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);

	void makeSound() const;
};

#endif
