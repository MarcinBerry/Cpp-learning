// 7_3.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

void getSinCos(double degress, double &sinOut, double &cosOut)
{
	const double pi = 3.14159265358979323846;
	double radians = degress * pi / 180.0;
	sinOut = std::sin(radians);
	cosOut = std::cos(radians);
}
int main()
{
	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);

	std::cout << "The sin is " << sin << "\n";
	std::cout << "The cos is " << cos << "\n";
    return 0;
}

