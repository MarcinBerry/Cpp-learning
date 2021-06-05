#include <pch.h>
#include <iostream>

double readNumber()
{
	std::cout << "Enter a number: ";
	double x;
	std::cin >> x;
	return x;
}
char choose()
{
	std::cout << "Enter a symbol ('+', '-', '*', '/'): ";
	char x;
	std::cin >> x;
	return x;
}
void calculate(int x, int y, char choose)
{
	switch (choose)
	{
	case '+':		std::cout << "Result: " << x + y;	break;
	case '-':		std::cout << "Result: " << x - y;	break;
	case '*':		std::cout << "Result: " << x * y;	break;
	case '/':		std::cout << "Result: " << x / y;	break;
	default:		std::cout << "Wrong operator!"; break;
	}
}