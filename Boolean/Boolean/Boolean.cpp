// Boolean.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
//bool isEqual(int x, int y)
//{
//	return (x == y);
//}
bool isPrime(int x)
{
	if (x == 2)
		return true;
	if (x == 3)
		return true;
	if (x == 5)
		return true;
	if (x == 7)
		return true;
	return false;
}
int main()
{
	/*
	std::cout << true << std::endl;
	std::cout << false << std::endl;
	std::cout << std::boolalpha;
	std::cout << true << std::endl;
	std::cout << false << std::endl;
	std::cout << std::noboolalpha;
	
	if (true)
		std::cout << "The condition is true" << std::endl;
	else
		std::cout << "The condition is false" << std::endl;
	
	std::cout << "Enter an integer: ";
	int x; 
	std::cin >> x;
	std::cout << "Enter another integer: ";
	int y;
	std::cin >> y;
	if (isEqual(x, y))
		std::cout << x << " and " << y << " are equal" << std::endl;
	else
		std::cout << x << " and " << y << " are not equal" << std::endl;
	*/
	std::cout << "Enter a integer: ";
	int x;
	std::cin >> x;
	if (isPrime(x))
		std::cout << "Your number is prime." << std::endl;
	else
		std::cout << "Your number in not prime." << std::endl;

    return 0;
}

