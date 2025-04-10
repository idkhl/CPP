#include "Span.hpp"

template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end) {
	if (std::distance(begin, end) > static_cast<int>(_size - _vec.size()))
		throw SpanFull();
	_vec.insert(_vec.end(), begin, end);
}
