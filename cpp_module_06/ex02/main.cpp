#include "Base.h"

int main()
{
	Base *p = generate();
	identify(*p);
	identify(p);
	delete p;
}
