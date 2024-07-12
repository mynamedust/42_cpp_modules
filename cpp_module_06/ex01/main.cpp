#include "Serializer.h"

int main()
{
	Data coord;
	coord.x = 1231;
	coord.y = 53;
	Data *ptr = &coord;
	uintptr_t uptr = Serializer::serialize(ptr);
	Data *dptr = Serializer::deserialize(uptr);

	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "dptr = " << dptr << std::endl;
	std::cout << "x: " << ptr->x << ", y: " << ptr->y << std::endl;
	std::cout << "dx: " << dptr->x << ", dy: " << dptr->y << std::endl;
	std::cout << "uptr: " << uptr << std:: endl;
}
