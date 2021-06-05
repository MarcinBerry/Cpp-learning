#include "pch.h"
#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number: ";
	int in;
	std::cin >> in;
	return in;
}

void writeAnswer(int x)
{
	std::cout << "Result: " << x;
}