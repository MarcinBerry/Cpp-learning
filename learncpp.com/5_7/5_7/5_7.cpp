// 5_7.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

/*
int main()
{
	for (int iii = 0; iii <= 20; iii+=2)
	{
			std::cout << iii << " ";
		
	}
    return 0;
}
*/

int sumTo(int value)
{
	int sum = 0;
	for (int iii = 1; iii <= value; iii++)
	{
		sum += iii;
	}

	return sum;
}
int main()
{
	int value;
	std::cout << "Enter a value: ";
	std::cin >> value;

	std::cout << "Your result: " << sumTo(value) << std::endl;
	return 0;
}