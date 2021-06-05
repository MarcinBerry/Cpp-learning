#include "stdafx.h"
#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number: ";
	int num;
	std::cin >> num;
	return num;
}
void writeAnswer(int answer)
{
	std::cout << "your answer is: " << answer << std::endl;
}