#ifndef CLASS_MUTANTSTACK_HPP
# define CLASS_MUTANTSTACK_HPP

# include <algorithm>
# include <stack>

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


template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

	class iterator {
	public:

		iterator(typename Container::iterator internal)
			: _internal(internal) {
			if (DEBUG) {
				std::cout << GREEN << "Constructing an iterator";
				std::cout << STOP_COLOR << std::endl;
			}
		}

		iterator(const MutantStack::iterator& original)
			: _internal(original._internal) {
			if (DEBUG) {
				std::cout << GREEN << "Copy constructing an iterator";
				std::cout << STOP_COLOR << std::endl;
			}
		}

		MutantStack::iterator&	operator=(const MutantStack::iterator& original) {
			if (DEBUG) {
				std::cout << GREEN << "Copy assigning an iterator";
				std::cout << STOP_COLOR << std::endl;
			}
			if (this != &original)
				_internal = original._internal;
			return (*this);
		}

		~iterator() {
			if (DEBUG) {
				std::cout << RED << "Destructing an iterator";
				std::cout << STOP_COLOR << std::endl;
			}
		}

		T&	operator*() const {
			return (*_internal);
		}

		MutantStack::iterator	operator++() {
			++_internal;
			return (*this);
		}

		MutantStack::iterator	operator++(int) {

			MutantStack::iterator	tmp = *this;
			++_internal;
			return (tmp);
		}

		MutantStack::iterator	operator--() {
			--_internal;
			return (*this);
		}

		MutantStack::iterator	operator--(int) {

			MutantStack::iterator	tmp = *this;
			--_internal;
			return (tmp);
		}

		bool	operator!=(const iterator & comp) const {
			return (_internal != comp._internal);
		}

		bool	operator==(const iterator & comp) const {
			return (_internal == comp._internal);
		}

	private:
		typename Container::iterator	_internal;

	};

	iterator	begin() {
		// When accessing parent member inherited through templates,
		// We can use either this->
		return iterator(this->c.begin());
		// or explicitly the parent's type
		// return iterator(std::stack<T, Container>::c.begin());
		// See : https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members
	}

	iterator	end() {
		return iterator(this->c.end());
	}


};

// Recycled from ex00 for testing purposes
template<typename T>
void printContainer(T& container) {
	int i = 0;
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
	{
		std::cout << "[" << i << "] = " << *iter << std::endl;
		i++;
	}
}

#endif
