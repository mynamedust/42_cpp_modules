#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack<T>& other);
	MutantStack<T> &operator=(const MutantStack<T>& other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin();
	iterator end();
};

#endif
