#include "MateriaSource.hpp"

//Constructors
MateriaSource::MateriaSource() {
	std::cout << "[MateriaSource] created" << std::endl;
	for (int i = 0; i < 4; ++i) {
		_materiaTemps[i] = NULL;
	}
};

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materiaTemps[i])
			delete _materiaTemps[i];
	}
	std::cout << "[MateriaSource] destroyed" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "[MateriaSource] copied" << std::endl;
	for (int i = 0; i < 4; ++i) {
		_materiaTemps[i] = NULL;
	}
	*this = other;
};

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->_materiaTemps[i])
				delete this->_materiaTemps[i];
			this->_materiaTemps[i] = other._materiaTemps[i];
		}
	}
	return *this;
};

//Methods
void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (_materiaTemps[i] == NULL) {
			_materiaTemps[i] = materia;
			std::cout << "[MateriaSource] " << materia->getType() << " type materia was learned" << std::endl;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 3; i >= 0; i--) {
		if (_materiaTemps[i] && _materiaTemps[i]->getType() == type) {
			std::cout << "[MateriaSource] " << type << " type materia was created" << std::endl;
			return _materiaTemps[i]->clone();
		}
	}
	return NULL;
}