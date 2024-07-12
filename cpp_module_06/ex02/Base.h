#ifndef BASE_H
#define BASE_H

#include <cstdlib>
#include <iostream>

class Base {
public:
	virtual ~Base();
};

Base * generate(void);
void identify(Base& p);
void identify(Base* p);

#include "A.h"
#include "B.h"
#include "C.h"

#endif