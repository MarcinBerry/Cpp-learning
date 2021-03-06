// 7_14.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cstdarg>

double findAvarage(int count, ...)
{
	double sum = 0;

	va_list list;

	va_start(list, count);

	for (int arg{ 0 }; arg < count; ++arg)
		sum += va_arg(list, int);

	va_end(list);
	return sum / count;
}

int main()
{
	std::cout << findAvarage(5, 1, 2, 3, 4, 5) << "\n";
	std::cout << findAvarage(6, 1, 2, 3, 4, 5, 6) << "\n";
    return 0;
}

