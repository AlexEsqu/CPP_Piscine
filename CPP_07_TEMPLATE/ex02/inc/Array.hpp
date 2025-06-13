#ifndef CLASS_ARRAY_H
# define CLASS_ARRAY_H

# include <stdexcept>
# include <iostream>
# include <stdlib.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define STOP_COLOR "\033[0m"

# define FAINT "\033[2m"
# define BOLD "\033[1m"
# define STOP_STYLE "\033[22m"

# define ITALIC "\033[3m"
# define STOP_ITALIC "\033[23m"

# ifndef DEBUG
#  define DEBUG 0
# endif

template<typename T>
class Array {

	private:

		int	_size;
		T*	_content;

	public:

		Array(int n = 0)
			: _size(n)
		{
			if (DEBUG) {
				std::cout << GREEN << "Constructing an Array of size ";
				std::cout << _size << STOP_COLOR << std::endl;
			}

			if (_size > 0)
				_content = new T[_size];
			else
				_content = NULL;

			for (int i = 0; i < _size; i++) {
				_content[i] = T();
			}
		}

		Array(const Array& original)
			: _size(original._size)
		{
			if (DEBUG) {
				std::cout << GREEN << "Copy constructing an Array of size ";
				std::cout << _size << STOP_COLOR << std::endl;
			}

			if (_size > 0)
				_content = new T[_size];
			else
				_content = NULL;

			for (int i = 0; i < _size; i++) {
				_content[i] = original._content[i];
			}
		}

		~Array() {
			if (DEBUG) {
				std::cout << RED << "Destructing an Array of size ";
				std::cout << _size << STOP_COLOR << std::endl;
			}

			delete[] _content;
		}

		Array&			operator=(const Array& original)
		{
			if (DEBUG) {
				std::cout << GREEN << "Copy assigning an Array of size ";
				std::cout << original._size << STOP_COLOR << std::endl;
			}

			if (this != original) {
				delete[] _content;
				_size = original._size;
				for (int i = 0; i < _size; i++) {
					_content[i] = original._content[i];
				}
			}
			return *this;
		}

		T&				operator[](int idx)
		{
			if (_size == 0 || idx >= _size || idx < 0)
				throw std::out_of_range("Out of bound");
			return _content[idx];
		}

		const T&		operator[](int idx) const
		{
			if (_size == 0 || idx >= _size || idx < 0)
				throw std::out_of_range("Out of bound");
			return _content[idx];
		}

		int	size() const
		{
			return (_size);
		}

};

#endif
