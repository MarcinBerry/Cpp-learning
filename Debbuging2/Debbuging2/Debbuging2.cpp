// Debbuging2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

void CallC()
{
	std::cout << "C called" << std::endl;
}
void CallB()
{
	std::cout << "Bcalled" << std::endl;
	CallC();
}
void CallA()
{
	CallB();
	CallA();
}

int main()
{
	/*int x = 1;
	std::cout << x << " ";

	x = x + 1;
	std::cout << x << " ";

	x = x + 2;
	std::cout << x << " ";

	x = x + 4;
	std::cout << x << " ";
	*/
	CallA();
    return 0;
}

