#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
typedef std::string string;

class ICharacter;

class AMateria {
protected:
	string _type;
public:
	AMateria();
	virtual ~AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#include "ICharacter.hpp"
#endif
