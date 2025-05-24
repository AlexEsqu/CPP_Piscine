#ifndef ITER_H
# define ITER_H

template<typename P, typename T, typename F>
void	iter(P address, T lenght, F function)
{
	for (T iter = 0; iter < lenght; iter++) {
		function(address[iter]);
	}
}

template<typename T>
void	printAnyElem(T elem)
{
	std::cout << "Element is " << elem << std::endl;
}

template<typename T>
void	incrementAnyElem(T& elem)
{
	elem++;
}


#endif
