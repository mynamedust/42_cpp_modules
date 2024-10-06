#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <iostream>

int main() {
	MutantStack<int> mstack;
	std::cout << "Pushing elements onto the stack..." << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterating over stack elements:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	std::cout << "Size of copied stack: " << s.size() << std::endl;

	return 0;
}
