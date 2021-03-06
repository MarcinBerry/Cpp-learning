// Chapter2_4.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include "constants.h"

// Pobiera wartość pierwotnej wysokości od użytkownika
double getInitialHeight()
{
	std::cout << "Enter a initial height: " << "\n";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}
//Oblicza dystans piłki od ziemi
double calculateHeight(double initialHeight, int seconds)
{
	//używam podanego wzoru
	double distansFallen = (myConstants::grav * (seconds*seconds)) / 2;
	double currentHeight = initialHeight - distansFallen;
	return currentHeight;
}
//wyświetla wartość wysokości w konkretnej sekundzie
void printHeight(double currentHeight, int seconds)
{
	if (currentHeight > 0)
		std::cout << "At " << seconds << " seconds, the ball is at height :" << currentHeight << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}
void calculateAndPrintHeight(double initialHeight, int seconds)
{
		printHeight(calculateHeight(initialHeight, seconds), seconds);
}
int main()
{
	double initialHeight = getInitialHeight();
	calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);
}

