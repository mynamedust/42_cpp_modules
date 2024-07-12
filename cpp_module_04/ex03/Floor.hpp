#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

typedef struct s_item {
	AMateria *item;
	s_item *next;
} n_item;

class Floor {
private:
	n_item* _items;
public:
	Floor();
	~Floor();
	Floor(const Floor &other);
	Floor &operator=(const Floor &other);

	void drop(AMateria *item);
	void show();
};


#endif
