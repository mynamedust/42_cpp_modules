#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() {
	std::cout << "NULL size array param constructor called." << std::endl;
	arr = NULL;
	len = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	std::cout << n << " size array param constructor called." << std::endl;
	arr = new T[n];
	len = n;
}

template<typename T>
Array<T>::Array(const Array<T>& other) {
	std::cout << other.len << " size array copy constructor called." << std::endl;
	arr = new T[other.len];
	len = other.len;

	for (size_t i = 0; i < other.len; i++)
		arr[i] = other[i];
}

template <typename T>
Array<T>::~Array() {
	std::cout << len << " size array destructor called." << std::endl;
	delete []arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	std::cout << other.len << " size array = operator called." << std::endl;
	if (this != &other){
		delete []arr;

		arr = new T[other.len];
		for (unsigned int i = 0; i < other.len; i++)
			arr[i] = other.arr[i];
		len = other.len;
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= len)
		throw std::out_of_range("Trying access out of range");
	return arr[i];
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const{
	if (i >= len)
		throw std::out_of_range("Trying access out of range");
	return arr[i];
}

template<typename T>
size_t Array<T>::size() const {
	return len;
}

#endif