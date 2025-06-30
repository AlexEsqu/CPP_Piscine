#ifndef STOPWATCH_CLASS_H
# define STOPWATCH_CLASS_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sys/time.h>

class	StopWatch {

	public:
				StopWatch(std::string name);
				StopWatch(const StopWatch& original);
				~StopWatch();
	StopWatch&	operator=(const StopWatch& original);

	void		start();
	void		stop();
	void		printTime();
	std::string	getName();
	double		getTimeInUsec();

	private:
		std::string	_name;
		timeval		_start;
		timeval		_stop;
		double		_uSecTotal;
};

#endif
