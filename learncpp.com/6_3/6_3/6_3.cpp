// 6_3.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

/*
int main()
{
	int scores[] = { 84,92,76,81,56 };
	const int numStudents = sizeof(scores) / sizeof(scores[0]);
	int totalScore = 0;

	int maxScore = 0;
	for (int student = 0; student < numStudents; ++student)
		if (scores[student] > maxScore)
			maxScore = scores[student];

	std::cout << maxScore;
    return 0;
}




int main()
{
	//geting input from user

	int number = 0;
	do
	{
		std::cout << "Enter a number between 1 to 9: ";
		std::cin >> number;

		if (std::cin.fail())
			std::cin.clear();

		std::cin.ignore(32767, '\n');


	} while (number < 1 || number > 9);


	//printing array 

	int array[] = { 4,6,7,3,8,2,1,8,5 };
	int arrayLength = sizeof(array) / sizeof(array[0]);

	

	for (int index = 0; index < arrayLength; ++index)
		std::cout << array[index] << std::endl;
	for (int index = 0; index < arrayLength; ++index)
	{
		if (array[index] == number)
			std::cout << "index of your number is " << index;
	}
	return 0;
}


*/

int main()
{
	int scores[] = { 84, 92, 76, 81, 56 };
	const int numStudents = sizeof(scores) / sizeof(scores[0]);

	int maxIndex = 0; // keep track of our largest score

					  // now look for a larger score
	for (int student = 0; student < numStudents; ++student)
		if (scores[student] > scores[maxIndex])
			maxIndex = student;
	
	std::cout << "The best score was " << maxIndex << '\n';

	return 0;
}