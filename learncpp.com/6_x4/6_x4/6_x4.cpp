// 6_x4.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <iostream>
/*
void printCString(const char *str)
{
	while (*str != '\0')
	{
		std::cout << *str;

		++str;
	}
}

int main()
{

	printCString("Hello, world!");

    return 0;
}
*/
int main()
{
	int x = 5;
	int y = 7;

	const int *ptr = &x;
	std::cout << *ptr;

	return 0;
}