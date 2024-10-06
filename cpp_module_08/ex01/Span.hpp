#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span {
	std::vector<int> _arr;
	unsigned int _cap;
public:
	Span();
	Span(const unsigned int cap);
	Span(const Span& other);
	Span& operator=(const Span& other);


	void addNumber(int value);
	void fill(unsigned int count);
	int shortestSpan() const;
	int longestSpan() const;

	class SpanOverflow : public std::exception {
		const char *what() const throw();
	};

	class NotEnoughElem : public std::exception {
		const char *what() const throw();
	};

	class FillOverflow : public std::exception {
		const char *what() const throw();
	};
};



#endif //SPAN_HPP
