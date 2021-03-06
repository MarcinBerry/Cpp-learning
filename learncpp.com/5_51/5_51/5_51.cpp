// 5_51.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Ball
{
private:
	std::string m_color ;
	double m_radius ;

public:
	Ball(const double radius)
	{
		m_color = "black";
		m_radius = radius;
	}
	Ball(const std::string &color = "black", const double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}
	void print()
	{
		std::cout << " Color: " << m_color << ", " << "Radius: " << m_radius << "\n";
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();
    return 0;
}

