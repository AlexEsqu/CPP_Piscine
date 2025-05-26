#include "Span.hpp"

Span::Span(unsigned int max)
	: _max(max)
{

}

Span::~Span()
{

}

Span::Span(const Span& original)
	: _max(original._max)
	, _content(original._content)
{

}

Span&	Span::operator=(const Span& original)
{
	_max = original._max;
	_content = original._content;
	return *this;
}

void	Span::addNumber(int num)
{
	if (_content.size() == _max)
		throw std::logic_error("ERROR: Span is filled to the brim.");
	_content.insert(num);
}

int		Span::shortestSpan()
{
	if (_content.size() < 2)
		throw std::logic_error("ERROR: Span does not contain a minimum 2 elements.");

	int								shortest = __INT_MAX__;
	std::multiset<int>::iterator	curr = _content.begin();
	std::multiset<int>::iterator	next = ++_content.begin();
	while (next != _content.end()) {
		shortest = std::min(shortest, (*next - *curr));
		curr++;
		next++;
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (_content.size() < 2)
		throw std::logic_error("ERROR: Span does not contain a minimum 2 elements.");
	return (*_content.rbegin() - *_content.begin());
}

unsigned int	Span::getSize()
{
	return (_content.size());
}



