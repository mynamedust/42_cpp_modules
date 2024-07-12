#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Floor.hpp"

class Character : public ICharacter{
private:
	AMateria* _inventory[4];
	string _name;
	static Floor floor;
public:
	Character();
	Character(const string& name);
	~Character();
	Character(const Character &other);
	Character &operator=(const Character &other);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};


#endif
