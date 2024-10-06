#include "Span.hpp"

Span::Span() : _cap(0) {
	std::cout << "Default span constructor called. Capacity: 0" << std::endl;
}

Span::Span(const unsigned int cap) : _cap(cap) {
	std::cout << "Param span constructor called. Capacity: " << cap << std::endl;
}

Span::Span(const Span& other) {
	_cap = other._cap;
	_arr = other._arr;
	std::cout << "Copy span constructor called. Capacity: " << _cap << std::endl;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_cap = other._cap;
		_arr = other._arr;
	}
	return *this;
}

void Span::addNubmer(int value) {
	if (_arr.size() >= _cap)
		throw SpanOverflow();
	_arr.push_back(value);
}

int Span::longestSpan() const {
	if (_arr.size() <= 2)
		throw NotEnoughElem();
	return *std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr.begin(), _arr.end());
}

int Span::shortestSpan() const {
	if (_arr.size() <= 2)
		throw NotEnoughElem();
	std::vector<int> tmpArr = _arr;
	std::sort(tmpArr.begin(), tmpArr.end());

	int span = tmpArr[1] - tmpArr[0];
	for (size_t i = 2; i < tmpArr.size(); i++)
		span = std::min(span, tmpArr[i] - tmpArr[i - 1]);

	return span;
}

void Span::fill(unsigned int count) {
	if (_arr.size() + count > _cap)
		throw FillOverflow();
	while(count--)
		_arr.push_back(count);
}

const char *Span::NotEnoughElem::what() const throw() {
	return "Not enough elements. Need minimum 2.";
}

const char *Span::SpanOverflow::what() const throw()
{
	return "Span already filled.";
}

const char *Span::FillOverflow::what() const throw()
{
	return "Too many items for fill.";
}


