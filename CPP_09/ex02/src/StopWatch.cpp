#include "StopWatch.hpp"

			StopWatch::StopWatch(std::string name)
	: _name(name)
{
	#ifdef DEBUG
	//std::cout << "Calling StopWatch constructor" << std::endl;
	#endif
}

			StopWatch::StopWatch(const StopWatch& original)
	: _name(original._name)
	, _start(original._start)
	, _stop(original._stop)
	, _uSecTotal(original._uSecTotal)
{
	#ifdef DEBUG
	//std::cout << "Calling StopWatch copy constructor" << std::endl;
	#endif
}
			StopWatch::~StopWatch()
{
	#ifdef DEBUG
	//std::cout << "Calling StopWatch destructor" << std::endl;
	#endif
}
StopWatch&	StopWatch::operator=(const StopWatch& original)
{
	#ifdef DEBUG
	//std::cout << "Calling StopWatch copy assignement operator" << std::endl;
	#endif

	if (this != &original) {
		_name = original._name;
		_start = original._start;
		_stop = original._stop;
		_uSecTotal = original._uSecTotal;
	}

	return (*this);
}

void		StopWatch::start()
{
	gettimeofday(&_start, NULL);
}

void		StopWatch::stop()
{
	gettimeofday(&_stop, NULL);
	_uSecTotal = (_stop.tv_sec - _start.tv_sec) * 1e6 + (_stop.tv_usec - _start.tv_usec);
}

std::string	StopWatch::getName()
{
	return (_name);
}

double		StopWatch::getTimeInUsec()
{
	return (_uSecTotal);
}

void		StopWatch::printTime()
{
	std::cout << std::setprecision(5) << getTimeInUsec();
}
