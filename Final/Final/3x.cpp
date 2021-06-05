#include "pch.h"
#include <iostream>
#include "constants.h"

double readHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double h;
	std::cin >> h;
	return h;
}
//distance Fallen
double calculate(double &meters, int seconds)
{
	meters = meters - (myConstants::gravity * (seconds*seconds)) / 2;
	return meters;
}

void print(double x, int seconds)
{
	if(x > 0)
		std::cout << "At " << seconds << ", the ball is at height: " << x << " meters\n";
	else 
		std::cout << "At " << seconds << ", the ball is at height: " << 0 << " meters\n";
}