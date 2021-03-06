// 5_10.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

double getDouble()
{
	while (true)
	{
		std::cout << "Enter a double value: ";
		double x;
		std::cin >> x;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Opps, that input is valid. Please try again.\n";
		}
		else
			std::cin.ignore(32767, '\n');
			return x;
	}
}

char getOperator()
{
	while (true)
	{
		std::cout << "Enter one of the following: +, -, * or /: ";
		char op;
		std::cin >> op;

		std::cin.ignore(32767, '\n');

		if (op == '+' || op == '-' || op == '*' || op == '/')
			return op;
		else
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is valid. Please try again.\n";
	}
}
void printResult(double x, char op, double y)
{
	if (op == '+')
		std::cout << x << " + " << y << " is " << x + y << std::endl;
	else if (op == '-')
		std::cout << x << " - " << y << " is " << x - y << std::endl;
	else if (op == '*')
		std::cout << x << " * " << y << " is " << x * y << std::endl;
	else if (op == '/')
		std::cout << x << " / " << y << " is " << x / y << std::endl;
	else
		std::cout << "Something went wrong: printResult() gor an invalid operator.";
}

int main()
{
	double x = getDouble();
	char op = getOperator();
	double y = getDouble();

	printResult(x, op, y);

    return 0;
}

