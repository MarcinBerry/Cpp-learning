// 12.x.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class Shape
{
public:
	virtual ~Shape() {}
	virtual std::ostream& print(std::ostream &out) const = 0;

	friend std::ostream& operator<< (std::ostream &out, const Shape &shape) 
	{
		return shape.print(out);
	}
};

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{
	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << " )";
		return out;
	}
};
class Triangle : public Shape
{
protected:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle(const Point &p1, const Point &p2, const Point &p3)
		: m_p1(p1), m_p2(p2), m_p3(p3)
	{
	}

	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Traignle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
		return out;
	}
};

class Circle : public Shape
{
protected:
	Point m_p1;
	int m_radius;

public:
	Circle(const Point &p1, int radius)
		: m_p1(p1), m_radius(radius)
	{
	}
	virtual std::ostream& print(std::ostream &out) const override
	{
		out << "Triangle(" << m_p1 << ", radius " << m_radius << ")";
		return out;
	}
	int getRadius()
	{
		return m_radius;
	}
};
int getLargestRadius(const std::vector<Shape*> &v)
{
	int largestRadius{ 0 };
	for (auto const &element : v)
	{
		if (Circle *c = dynamic_cast<Circle*>(element))
		{
			if (c->getRadius() > largestRadius)
				largestRadius = c->getRadius();
		}
	}
	return largestRadius;
}
int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	//print each shape in vector v on its own line here 
	for (auto const &element : v)
	{
		std::cout << *element << '\n';
	}

	std::cout << " The largest radius is: " << getLargestRadius(v) << '\n';

	//delete each element in the vector here
	for (auto const &element : v)
		delete element;
    return 0;
}

