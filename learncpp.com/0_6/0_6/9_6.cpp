// 0_6.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*
class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	friend bool operator> (const Cents &c1, const Cents &c2);
	friend bool operator<= (const Cents &c1, const Cents &c2);

	friend bool operator< (const Cents &c1, const Cents &c2);
	friend bool operator>= (const Cents &c1, const Cents &c2);
};

bool operator> (const Cents &c1, const Cents &c2)
{
	return c1.m_cents > c2.m_cents;
}

bool operator>= (const Cents &c1, const Cents &c2)
{
	return c1.m_cents >= c2.m_cents;
}

bool operator< (const Cents &c1, const Cents &c2)
{
	return !(c1.m_cents > c2.m_cents);
}

bool operator<= (const Cents &c1, const Cents &c2)
{
	return !(c1.m_cents >= c2.m_cents);
}

int main()
{
	Cents dime(10);
	Cents nickle(5);

	if (nickle > dime)
		std::cout << "a nickle is greater than a dime.\n";
	if (nickle >= dime)
		std::cout << "a nickle is greater than or equal to a dime.\n";
	if (nickle < dime)
		std::cout << "a dime is greater than a nickle.\n";
	if (nickle <= dime)
		std::cout << "a dime is greater than or equal to a nickle.\n";
    return 0;
}
*/
class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string make, std::string model)
		: m_make(make), m_model(model)
	{
	}

	friend bool operator== (const Car &c1, const Car &c2);
	friend bool operator!= (const Car &c1, const Car &c2);
	friend bool operator<  (const Car &c1, const Car &c2);
	friend std::ostream& operator<<(std::ostream& out, const Car &c);
};

bool operator== (const Car &c1, const Car &c2)
{
	return (c1.m_make == c2.m_make &&
		c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}

bool operator< (const Car &c1, const Car &c2)
{
	if (c1.m_make == c2.m_make)
		return c1.m_model < c2.m_model;
	else
		return c1.m_make < c2.m_make;
}
std::ostream& operator<<(std::ostream& out, const Car &c)
{
	out << "(" << c.m_make << ", " << c.m_model << ")";
	return out;
}
int main()
{
	std::vector<Car> v;
	v.push_back(Car("Toyota", "Corolla"));
	v.push_back(Car("Honda", "Accord"));
	v.push_back(Car("Toyota", "Camry"));
	v.push_back(Car("Honda", "Civic"));

	std::sort(v.begin(), v.end()); // requires an overloaded operator<

	for (auto &car : v)
		std::cout << car << '\n'; // requires an overloaded operator<<

	return 0;
}
