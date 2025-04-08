#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <class T>
class Array {

	private:
		T*		_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		~Array(void);
		Array& operator=(const Array& other);
		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		unsigned int size(void) const;

		class		OutOfRange : public std::exception
		{
			const char	*what(void) const throw();
		};
};

#endif