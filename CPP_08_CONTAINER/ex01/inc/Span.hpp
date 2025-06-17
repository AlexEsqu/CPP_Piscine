#ifndef CLASS_SPAN_H
# define CLASS_SPAN_H

# include <algorithm>
# include <set>
# include <stdexcept>
# include <iostream>

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

class Span {

	public:

		Span(unsigned int max);
		~Span();
		Span(const Span& original);
		Span&	operator=(const Span& original);

		void			addNumber(int num);
		int				shortestSpan();
		int				longestSpan();
		unsigned int	getSize();
		void			printSpan();

		template <typename T>
		void	addRange(const T& it_start, const T& it_end) {
			if (_content.size() + distance(it_start, it_end) > _max)
				throw std::logic_error("ERROR: Span is filled to the brim.");
			_content.insert(it_start, it_end);
		}


	private:

		unsigned int		_max;
		std::multiset<int>	_content;


};



#endif
