// 9_2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denomination;
public:
	Fraction(int numerator = 0, int denomination = 1) : m_numerator(numerator), m_denomination(denomination) 
	{
		reduce();
	}

	void print()
	{
		std::cout << m_numerator << "/" << m_denomination << "\n";
	}
	int gcd(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}
	void reduce()
	{
		int gcd = Fraction::gcd(m_numerator, m_denomination);
		m_numerator /= gcd;
		m_denomination /= gcd;
	}
	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int num);
	friend Fraction operator*(int num, const Fraction &f1);
	friend std::ostream& operator<< (std::ostream &out, const Fraction &frac);
	friend std::istream& operator>> (std::istream &in, Fraction &frac);

};
std::istream& operator>> (std::istream &in, Fraction &frac)
{
	char c;
	in >> frac.m_numerator;
	in >> c;
	in >> frac.m_denomination;
	frac.reduce();
	return in;
}
std::ostream& operator<< (std::ostream &out, const Fraction &frac)
{
	out << frac.m_numerator << "/" << frac.m_denomination;
	return out;
}
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denomination * f2.m_denomination);
}
Fraction operator*(const Fraction &f1, int num)
	{
	return Fraction(f1.m_numerator * num, f1.m_denomination );
	}
Fraction operator*(int num, const Fraction &f1)
{
	return Fraction(f1.m_numerator * num, f1.m_denomination);
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}

