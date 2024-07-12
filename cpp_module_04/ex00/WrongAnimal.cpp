#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() {
	_type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const string &type) {
	_type = type;
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
};

string WrongAnimal::getType() const{
	return _type;
}

void WrongAnimal::makeSound() const{
	std::cout << _type << ": *wrong animal sound*" << std::endl;
}