#include "Cure.hpp"

//Constructors
Cure::Cure() : AMateria("cure") {
	std::cout << "[Cure] new materia created" << std::endl;
};

Cure::~Cure() {
	std::cout << "[Cure] materia deleted" << std::endl;
};

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << "[Cure] materia copied" << std::endl;
	*this = other;
};

Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
};

//Methods
AMateria* Cure::clone() const {
	std::cout << "[Cure] new materia cloned" << std::endl;
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}