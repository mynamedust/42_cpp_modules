#include "AMateria.hpp"

//Constructors
AMateria::AMateria() {
	_type = "*no type*";
	std::cout << "[AMateria] created new" << std::endl;
};

AMateria::AMateria(const std::string &type) {
	_type = type;
	std::cout << "[AMateria] created new " << _type << std::endl;
}

AMateria::~AMateria() {
	std::cout << "[AMateria] " << _type << " deleted" << std::endl;
};

AMateria::AMateria(const AMateria &other) {
	*this = other;
	std::cout << "[AMateria] " << _type << " copied" << std::endl;
};

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
};

//Methods
std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "[AMateria] " << _type << " used on " << target.getName() << std::endl;
}
