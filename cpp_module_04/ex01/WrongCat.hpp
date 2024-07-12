#ifndef INC_42_CPP_MODULE_04_WRONGCAT_HPP
#define INC_42_CPP_MODULE_04_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
};


#endif
