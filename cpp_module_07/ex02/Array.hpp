#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array {
	T *arr;
	size_t len;
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& other);
	~Array();

	Array<T>& operator=(const Array<T>& other);
	T&	operator[](unsigned int i);
	const T& operator[](unsigned int i) const;

	size_t size() const;
};

#include "Array.tpp"
#endif
