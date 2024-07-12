#include "Character.hpp"

Floor Character::floor = Floor();

//Constructors
Character::Character() {
	_name = "*no name*";
	std::cout << "[Character] " << _name << " created" << std::endl;
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
};

Character::Character(const string& name) {
	this->_name = name;
	std::cout << "[Character] " << _name << " created" << std::endl;
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
};

Character::~Character() {
	std::cout << "[Character] " << _name << " destroyed" << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i])
			delete _inventory[i];
	}
};

Character::Character(const Character &other) {
	std::cout << "[Character] " << _name << " copied";
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	*this = other;
};

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
};

//Methods
string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	int nullSpace = -1;

	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == m)
			return;
		if (_inventory[i] == NULL)
			nullSpace = i;
	}
	if (nullSpace >= 0) {
		_inventory[nullSpace] = m;
		std::cout << "[Character] " << _name << " equipped " << m->getType() << " to slot " << nullSpace << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		std::cout << "[Character] " << _name << " dropped " << _inventory[idx]->getType() << " to the floor " << std::endl;
		Character::floor.drop(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		std::cout << "[Character] " << _name << " used " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
		_inventory[idx]->use(target);
	}
}

