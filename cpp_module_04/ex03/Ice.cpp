#include "Ice.hpp"

//Constructors
Ice::Ice() : AMateria("ice") {
	std::cout << "[Ice] new materia created" << std::endl;
};

Ice::~Ice() {
	std::cout << "[Ice] materia deleted" << std::endl;
};

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cout << "[Ice] materia copied" << std::endl;
	*this = other;
};

Ice &Ice::operator=(const Ice &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
};

//Methods
AMateria* Ice::clone() const {
	std::cout << "[Ice] new materia cloned" << std::endl;
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
