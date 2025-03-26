#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span &other) : _size(other._size), _vec(other._vec) {}

Span &Span::operator=(const Span &other)
{
	_size = other._size;
	_vec = other._vec;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_vec.size() >= _size)
		throw std::overflow_error("Span is full");
	_vec.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw NoSpan();
	std::sort(_vec.begin(), _vec.end());
	unsigned int shortest = std::abs(_vec[0] - _vec[1]);
	for (size_t i = 0 ; i < _vec.size() - 1 ; i++)
	{
		unsigned int diff = std::abs(_vec[i] - _vec[i + 1]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int	Span::longestSpan()
{
	if (_vec.size() < 2)
	{
		throw NoSpan();
		return -1;
	}
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return std::abs(min - max);
}