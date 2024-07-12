#include "Floor.hpp"

Floor::Floor() {
	_items = NULL;
};

Floor::~Floor() {
	n_item *start = _items;
	while (_items && _items->next) {
		_items = _items->next;
		delete start;
		start = _items;
	}
	delete _items;
};

Floor::Floor(const Floor &other) {
	*this = other;
};

Floor &Floor::operator=(const Floor &other) {
	if (this != &other) {
		this->_items = other._items;
	}
	return *this;
};

void Floor::drop(AMateria *materia) {
	n_item* newitem;

	newitem = new n_item;
	newitem->item = materia;
	newitem->next = NULL;

	if (!_items) {
		_items = newitem;
//		show();
		return;
	}
	while (_items->next)
		_items = _items->next;
	_items->next = newitem;
//	show();
}

void Floor::show() {
	n_item* current = _items;

	while (current != NULL) {
		std::cout << current->item->getType() << std::endl;
		current = current->next;
	}
	std::cout << std::endl;
}