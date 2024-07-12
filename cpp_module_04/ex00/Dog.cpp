#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
};

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
};

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
};

void Dog::makeSound() const{
	std::cout << _type << ": Woof" << std::endl;
}
