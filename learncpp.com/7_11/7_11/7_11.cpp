// 7_11.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>
/*
int factorial(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return factorial(num - 1) * num;
}
int main()
{
	std::cout << factorial(3);
    return 0;
}

int sumDigits(int x)
{
	if (x < 10)
		return x;
	else
		return sumDigits(x / 10) + x % 10;
}

int main()
{
	std::cout <<  sumDigits(93427);
	return 0;
}
*/

void toBinary(unsigned int x)
{
	if (x > 1)
		toBinary(x / 2);

	std::cout << x % 2;
}
int main()
{
	std::cout << "Enter a integer: ";
	int num;
	std::cin >> num;
	toBinary(num);
	return 0;
}