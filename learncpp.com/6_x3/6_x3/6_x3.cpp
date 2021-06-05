// 6_x3.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a{ 2 }, b{ 4 };

	std::cout << "number a is " << a << " number b is " << b << std::endl;

	swap(a, b);

	std::cout << "number a is " << a << " number b is " << b << std::endl;

    return 0;
}

