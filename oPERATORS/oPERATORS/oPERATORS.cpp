// oPERATORS.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
/*
int pow(int vase, int exp)
{
	int result = 1;
	while(exp)
	{
		if (exp & 1)
		{
			result *= base;
			exp >>= 1;
			base *= base;
		}
	}
	return result;
}
*/
int getNumber()
{
	std::cout << "Enter a number to check:" << std::endl;
	int x;
	std::cin >> x;
	return x;
}
bool isEven(int number)
{
	return number % 2 == 0;
}
int main()
{
	/*
	double x = std::pow(3.0, 4.0);
	std::cout << x << std::endl;
	
	int x{ 7 };
	int y{ 4 };
	
	std::cout << "int / int = " << x / y << std::endl;
	std::cout << "double / int = " << static_cast<double>(x) / y << std::endl;
	std::cout << "int / double = " << x / static_cast<double>(y) << std::endl;
	std::cout << " double / double = " << static_cast<double>(x) / static_cast<double>(y) << std::endl;
	
	int count = { 1 };
	while (count <= 100)
	{
		std::cout << count << " ";
		if (count % 20 == 0)
			std::cout << "\n";
		count++;
	}
	*/

	int number = getNumber();

	if (isEven(number))
		std::cout << "Your number is even" << std::endl;
	else
		std::cout << " Your number is odd" << std::endl;
	return 0;
}

