#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <cstdint>
#include <iostream>

typedef struct s_Data {
	int x;
	int y;
} Data;

class Serializer {
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};



#endif
