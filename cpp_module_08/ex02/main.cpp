#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <iostream>

int main() {
	// Создание объекта MutantStack
	MutantStack<int> mstack;

	// Проверка начального состояния стека
	std::cout << "Pushing elements onto the stack..." << std::endl;

	// Добавление элементов
	mstack.push(5);
	mstack.push(17);

	// Вывод верхнего элемента и размера стека
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	// Добавление дополнительных элементов
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Итерирование по стеку и вывод элементов
	std::cout << "Iterating over stack elements:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	// Создание копии стека
	std::stack<int> s(mstack);
	std::cout << "Size of copied stack: " << s.size() << std::endl;

	return 0;
}
