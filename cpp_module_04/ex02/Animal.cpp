#include "Animal.hpp"


Animal::Animal() {
	_type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
};

Animal::Animal(const string &type) {
	_type = type;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
};

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
};

Animal& Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
};

string Animal::getType() const{
	return _type;
}