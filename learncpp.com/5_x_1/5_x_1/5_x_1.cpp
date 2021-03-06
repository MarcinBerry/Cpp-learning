// 5_x_1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include "constants.h"
#include <ctime>
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

double calculateHeight(double initialHeight, int secondPassed)
{
	double distanceFallen = (myConstants::gravity * secondPassed * secondPassed) / 2;
	double currentHeight = initialHeight - distanceFallen;
	//if(currentHeight > 0.0)
		return currentHeight;
	//else
	//{
	//	currentHeight = 0.0;
	//	return currentHeight;
	//}
}

void printHeight(double height, int secondsPassed)
{
	if (height > 0.0)
	{
		std::cout << "At " << secondsPassed << " seconds, the ball is at height:\t" << height << " meters\n";
		
	}
	else
	{
		std::cout << "At " << secondsPassed << " seconds, the ball is on the ground.\n";
		
	}

}

void calculateAndPrintHeight(double initialHeight, int secondsPassed)
{ 
	double height = calculateHeight(initialHeight, secondsPassed);
	printHeight(height, secondsPassed);
}


int main()
{
	const double initialHeight = getInitialHeight();

	for (int ii = 0; true; ii++)
	{
		if ((calculateHeight(initialHeight, ii)) <= 0)
		{
			calculateAndPrintHeight(initialHeight, ii);
			break;
		}
		else
			calculateAndPrintHeight(initialHeight, ii);
	}
    return 0;
}

