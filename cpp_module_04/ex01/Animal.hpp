#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

typedef std::string string;

class Animal {
protected:
	string _type;
public:
	Animal();
	Animal(const string& type);
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	string getType() const;
	virtual void makeSound() const;
	virtual Brain* getBrain() const;
};

#endif
