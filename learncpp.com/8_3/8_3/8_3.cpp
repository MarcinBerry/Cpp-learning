// 8_3.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

class Point3d
{
private:

	double m_x, m_y, m_z;


public:
	void setValues(double x, double y, double z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	void print()
	{
		std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
	}
	bool isEqual(Point3d point)
	{
		if (m_x == point.m_x && m_y == point.m_y && m_z == point.m_z)
			return true;
		else
			return false;
	}
};

int main()
{
	Point3d point1;
	point1.setValues(1.0, 2.0, 3.0);

	Point3d point2;
	point2.setValues(1.0, 2.0, 3.0);
	
	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal.\n";
	else
		std::cout << "point1 and point2 are not equal.\n";
	
	Point3d point3;
	point3.setValues(3.0, 4.0, 5.0);

	if(point1.isEqual(point3))
		std::cout << "point1 and point2 are equal.\n";
	else
		std::cout << "point1 and point2 are not equal.\n";
    return 0;
}

