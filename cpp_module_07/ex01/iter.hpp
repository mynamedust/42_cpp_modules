#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T> void iter(T *arr, size_t len, void(*f)(T&)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T> void print(T &p)
{
	std::cout << p << std::endl;
}

#endif //ITER_H
