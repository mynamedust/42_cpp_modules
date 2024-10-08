#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <vector>
#include <list>
#include <iostream>

template<typename T>
int easyfind(T& container, int value) {
	typename T::iterator position = std::find(container.begin(), container.end(), value);
	if (position == container.end())
		throw std::invalid_argument("Container doesnt include value");
	return std::distance(container.begin(), position);
}

#endif
