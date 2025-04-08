#include "Array.hpp"

template <typename T>
Array<T>::Array(void): _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]()), _size(n) {
}

template <typename T>
Array<T>::Array(const Array& other): _array(NULL), _size(0){
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
	if (this != &other) {
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	{
		if (_array == NULL || i > _size - 1)
			throw OutOfRange();
		else
			return _array[i];
	}
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
    if (_array == NULL || i > _size - 1)
        throw OutOfRange();
    else
        return _array[i];
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

template <typename T>
const char	*Array<T>::OutOfRange::what(void) const throw()
{
	return "Index is out of range";
}