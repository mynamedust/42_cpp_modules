#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

typedef std::string string;

class WrongAnimal {
protected:
	string _type;
public:
	WrongAnimal();
	WrongAnimal(const string &type);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);

	void makeSound() const;
	string getType() const;
};


#endif
