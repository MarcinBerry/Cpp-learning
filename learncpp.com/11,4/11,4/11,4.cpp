// 11,4.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Fruit
{
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string name, std::string color) : m_name(name), m_color(color) { }
	std::string getName() const { return m_name; }
	std::string getColor() const { return m_color; }
};

class Apple : Fruit
{
private:
	double m_fiber;

public:
	Apple(std::string name, std::string color, double fiber) : Fruit(name, color), m_fiber(fiber) { }
	friend std::ostream& operator<< (std::ostream &out, const Apple &a)
	{
		out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.m_fiber << " )";
		return out;
	}
};


class Banana : Fruit
{
public:
	Banana(std::string name, std::string color) : Fruit(name, color) { }
	friend std::ostream& operator<< (std::ostream &out, const Banana &b)
	{
		out << "Banana(" << b.getName() << ", " << b.getColor() << " )";
		return out;
	}
};
int main()
{
	const Apple a("Red Delicious", "Red", 4.2);
	std::cout << a;
	const Banana b("Cavendish", "yellow");
	std::cout << b;
    return 0;
}

