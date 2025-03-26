#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _vec;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	class NoSpan : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Not enough numbers";
			}
	};

	class SpanFull : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Span is full";
			}
	};
};

#endif