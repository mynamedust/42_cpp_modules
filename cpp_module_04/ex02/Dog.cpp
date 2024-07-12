#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
};

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	if (brain)
		delete brain;
};

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)){
	std::cout << "Dog copy constructor called" << std::endl;
};

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->_type = other._type;
		*(this->brain) = *(other.brain);
	}
	return *this;
};

void Dog::makeSound() const{
	std::cout << _type << ": Woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}

