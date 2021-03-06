// 3_7.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

int getNumber()
{
	std::cout << "Enter a number beetwen 0 and 255" << std::endl;
	int number;
	std::cin >> number;
	return number;
}
int calculate(int x, int pow)
{
	//sprawdza czy nasze x jest większe od jakiejś potęgi liczby 2 i drukuje bit
	if (x >= pow)
		std::cout << "1";
	else
		std::cout << "0";
	//Jeśli x jest większe od potegi 2, odejmij ta potęgę
	if (x >= pow)
		return x - pow;
	else
		return x;
}

int main()
{
	int x = getNumber();
	x = calculate(x, 128);
	x = calculate(x, 64);
	x = calculate(x, 32);
	x = calculate(x, 16);
	std::cout << " ";
	x = calculate(x, 8);
	x = calculate(x, 4);
	x = calculate(x, 2);
	x = calculate(x, 1);
    return 0;
}

