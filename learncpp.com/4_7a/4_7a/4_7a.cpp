// 4_7a.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

struct Fraction
{
	int numerator;
	int denumerator;

};
void multiply(Fraction f1, Fraction f2)
{
	float x;
	x = static_cast<float>(f1.numerator * f2.numerator) / (f1.denumerator * f2.denumerator);
	std::cout << x << std::endl;
}
int main()
{
	Fraction f1;
	std::cout << "Enter a first numerator ";
	std::cin >> f1.numerator;

	std::cout << "Enter your first denumrator " << std::endl;
	std::cin >> f1.denumerator;

	Fraction f2;
	std::cout << "Enter a second numerator ";
	std::cin >> f2.numerator;

	std::cout << "Enter your second denumrator " << std::endl;
	std::cin >> f2.denumerator;
	
	multiply(f1, f2);
    return 0;
}

