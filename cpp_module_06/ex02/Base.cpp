#include "Base.h"

Base::~Base() {}

Base *generate() {
	srand(time(0));
	int i = rand() % 3;
	switch (i) {
		case 0:
			std::cout << "A type object created." << std::endl;
			return new A;
		case 1:
			std::cout << "B type object created." << std::endl;
			return new B;
		case 2:
			std::cout << "C type object created." << std::endl;
			return new C;
	}
	return new A;
}

void identify(Base* p) {
	std::string type;

	type = "Undefiend";
	if (dynamic_cast<A*>(p))
		type = "A";
	if (dynamic_cast<B*>(p))
		type = "B";
	if (dynamic_cast<C*>(p))
		type = "C";

	std::cout << type << " type object passed." << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A type object passed." << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B type object passed." << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C type object passed." << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	std::cout << "Undefiend type object passed." << std::endl;
}
