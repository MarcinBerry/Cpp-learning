// RelOperator.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
bool aproximetalyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
	double diff = fabs(a - b);
	if (diff <= absEpsilon)
		return true;
	return diff <= ((fabs(a) < fabs(b) ? fabs(a) : fabs(b)) * relEpsilon);
}
bool aproximetalyEqual(double a, double b, double epsilon)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a))*epsilon);
}
int main()
{
	/*
	std::cout << "Enter an integer: ";
	int x;
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y;
	std::cin >> y;

	if (x == y)
		std::cout << x << " equals " << y << std::endl;
	if (x != y)
		std::cout << x << " does not equals " << y << std::endl;
	if (x > y)
		std::cout << x << " is greater than " << y << std::endl;
	if (x < y)
		std::cout << x << " is less than " << y << std::endl;
	if (x >= y)
		std::cout << x << " is greater than or equal " << y << std::endl;
	if (x <= y)
		std::cout << x << " is less than or equal " << y << std::endl;
	
	double d1(100 - 99.99);
	double d2(10 - 9.99);
	if (d1 == d2)
		std::cout << "d1 = d2" << std::endl;
	else if (d1 > d2)
		std::cout << "d1 > d2" << std::endl;
	else if (d1 < d2)
		std::cout << "d1 < d2" << std::endl;
	*/
	double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
	std::cout << aproximetalyEqual(a, 1.0, 1e-8) << std::endl;
	std::cout << aproximetalyEqual(a - 1.0, 0.0, 1e-8) << std::endl;
	std::cout << aproximetalyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8) << std::endl;
    return 0;
}

