// 6_2b.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
/*
void passValue(int value)
{
	value = 99;
}

void passArray(int prime[5])
{
	prime[0] = 11;
	prime[1] = 7;
	prime[2] = 5;
	prime[3] = 3;
	prime[4] = 2;
}
int main()
{
	int value = 1;
	std::cout << "before passValue: " << value << "\n";
	passValue(value);
	std::cout << "after passValue: " << value << "\n";

	int prime[5] = { 2,3,5,7,11 };
	std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " <<
		prime[3] << " " << prime[4] << "\n";
	passArray(prime);
	std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " <<
		prime[3] << " " << prime[4] << "\n";
	return 0;
}

*/
namespace Animal
{
	enum Animal
	{
		CHICKEN,
		DOG,
		CAT,
		ELEPHANT,
		DUCK,
		SNAKE,
		MAX_ANIMALS
	};
}
int main()
{
	int numLegs[Animal::MAX_ANIMALS] = { 2,4,4,4,2,0 };

	std::cout << "Ilosc nog slonia: " << numLegs[Animal::ELEPHANT] << std::endl;
	return 0;
}