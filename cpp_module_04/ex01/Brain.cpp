#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain created. Congratulations!" << std::endl;
	ideasCount = 0;
};

Brain::~Brain() {
	std::cout << "Brain removed. What a pity." << std::endl;
};

Brain::Brain(const Brain &other) {
	std::cout << "Brain copied. Hello, Clone!" << std::endl;
	*this = other;
};

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (unsigned int i = 0; i < this->ideasCount; i++)
			this->ideas[i] = "";
		this->ideasCount = other.ideasCount;
		for (unsigned int i = 0; i < this->ideasCount; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
};

void Brain::addIdea(const string &idea) {
	if (ideasCount >= 100) {
		std::cout << "Too many ideas for this brain." << std::endl;
		return;
	}
	ideas[ideasCount++] = idea;
}

string Brain::getIdea(unsigned int number) const {
	if (number >= ideasCount) {
		std::cout << "Now in this brain " << ideasCount << " ideas. Your idea number is out of range." << std::endl;
		return "";
	}
	return ideas[number];
}

