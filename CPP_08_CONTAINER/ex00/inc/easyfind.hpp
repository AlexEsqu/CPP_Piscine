#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T& haystack, int needle) {
	typename T::iterator iter = find(haystack.begin(), haystack.end(), needle);
	if (iter != haystack.end())
		return iter;
	else
		throw std::out_of_range("Couldn't find the needle !!");
}

// MANUAL MODE
// template<typename T>
// typename T::iterator easyfind(T& haystack, int needle) {

// 	typename T::iterator iter = haystack.begin();
// 	while (iter != haystack.end()) {
// 		if (*iter == needle) {
// 			return iter;
// 		}
// 		iter++;
// 	}

// 	throw std::out_of_range("Couldn't find the needle !!");
// }

// ALTERNATIVE : RETURN CONTAINER.END()
// But then it is on the user to check that result != container.end()
// template<typename T>
// typename T::iterator easyfind(T& haystack, int needle) {

// 	typename T::iterator iter = haystack.begin();
// 	while (iter != haystack.end()) {
// 		if (*iter == needle) {
// 			return iter;
// 		}
// 		iter++;
// 	}

// 	return haystack.end();
// }

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

