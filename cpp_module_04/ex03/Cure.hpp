#ifndef INC_42_CPP_MODULE_04_CURE_HPP
#define INC_42_CPP_MODULE_04_CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();
	~Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);

	AMateria* clone() const;
	void use(ICharacter &target);
};


#endif
