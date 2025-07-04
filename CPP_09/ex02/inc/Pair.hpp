#ifndef PAIR_CLASS_H
# define PAIR_CLASS_H

# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <cstdlib>

class Pair {
public:

	// Canonical form

	Pair(int big, int small);
	Pair(int a);
	Pair(const Pair& original);
	~Pair();
	Pair&	operator=(const Pair& original);

	// Operator overloads

	bool	operator==(const Pair& comp) const;
	bool	operator==(const int& comp) const;
	bool	operator>(const Pair& comp) const;
	bool	operator>=(const Pair& comp) const;
	bool	operator<(const Pair& comp) const;
	bool	operator<=(const Pair& comp) const;

	// getters

	int		getBig() const;
	int		getSmall() const;
	bool	isStraggler() const;


private:
	int		big;
	int		small;
	bool	straggler;

};

std::ostream& operator<< (std::ostream& stream, const Pair& pair);

#endif
