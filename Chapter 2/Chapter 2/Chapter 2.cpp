// Chapter 2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

double math(double x, char op, double y)
{
	if (static_cast<int>(op) == 43)
		return (x + y);
	else if (static_cast<int>(op) == 45)
		return (x - y);
	else if (static_cast<int>(op) == 42)
		return (x * y);
	else if  (static_cast<int>(op) == 47)
		return (x / y);
	else
		return 0;
}

int main()
{
	/*
	2) 
	a/ int16_t
	b/ boolean
	c/constexp double 
	d/ uint16_t / int_least16_t
	e/ float 
	f/uint64_t
	g/char
	h/int_least16_t
	*/
	std::cout << "Entera a double value: " << std::endl;
	double x;
	std::cin >> x;

	std::cout << "Entera a second double value: " << std::endl;
	double y;
	std::cin >> y;

	std::cout << "Entera operator( + , - , * , / ): " << std::endl;
	char op;
	std::cin >> op;

	std::cout << math(x, op, y) << std::endl;
	return 0;
}

