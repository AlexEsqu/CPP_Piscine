#ifndef CLASS_ARRAY_H
# define CLASS_ARRAY_H

# include <stdexcept>

template<typename T>
class Array {

	private:

		unsigned int	_size;
		T*				_content;

	public:

		Array(unsigned int n = 0)
			: _size(n)
		{
			if (_size > 0)
				_content = new T[_size];
			else
				_content = NULL;

			for (unsigned int i = 0; i < _size; i++) {
				_content[i] = T();
			}
		}

		Array(const Array& original)
			: _size(original._size)
		{
			if (_size > 0)
				_content = new T[_size];
			else
				_content = NULL;

			for (int i = 0; i < _size; i++) {
				_content[i] = original._content[i];
			}
		}

		~Array() {
			delete[] _content;
		}

		Array&			operator=(const Array& original)
		{
			if (this != original) {
				delete[] _content;
				_size = original._size;
				for (int i = 0; i < _size; i++) {
					_content[i] = original._content[i];
				}
			}
			return *this;
		}

		T&				operator[](unsigned int idx)
		{
			if (_size == 0 || idx >= _size)
				throw std::out_of_range("Out of bound");
			return _content[idx];
		}

		const T&		operator[](unsigned int idx) const
		{
			if (_size == 0 || idx >= _size)
				throw std::out_of_range("Out of bound");
			return _content[idx];
		}

		unsigned int	size() const
		{
			return (_size);
		}

};

#endif
