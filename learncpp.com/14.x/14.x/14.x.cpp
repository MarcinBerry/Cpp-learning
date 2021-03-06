// 14.x.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>

class Fraction
{
private:
	int m_n;
	int m_d;

public:
	Fraction(int nom, int den)
		: m_n(nom), m_d(den) 
	{
		if (den == 0)
		{
			throw std::runtime_error("Invalid denominator!");
		}
		std::cout << (nom / den);
	}
};

int main()
{
	std::cout << "Enter the numerator: ";
	int numerator;
	std::cin >> numerator;
	std::cout << '\n';

	std::cout << "Enter the denominator: ";
	int denominator;
	std::cin >> denominator;
	std::cout << '\n';

	try {
		Fraction(numerator, denominator);
	}
	catch (std::exception &exception)
	{
		std::cout << "Caught a error: " << exception.what() << '\n';
	}
    return 0;
}

