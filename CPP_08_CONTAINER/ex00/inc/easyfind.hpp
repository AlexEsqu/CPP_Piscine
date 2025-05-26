#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T& haystack, int needle) {

	typename T::iterator iter = haystack.begin();
	while (iter != haystack.end()) {
		if (*iter == needle) {
			return iter;
		}
		iter++;
	}

	throw std::out_of_range("Couldn't find the needle !!");
}

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

#endif

