// 6_4.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

/*
int main()
{
	int x{ 2 };
	int y{ 4 };
	std::cout << "Before: " << x << " and " << y;
	std::swap(x, y);
	std::cout << "After: " << x << " and " << y << std::endl;
    return 0;
}


int main()
{
	const int length{ 5 };
	int array[length]{ 30,50,20,10,40 };

	//step throught every element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		//smallestIndex jest indexem najmniejszego emelemntu który napotkamy w tej iteracji
		//Zaczynamy przez założenie że najmniejszy element jest pierwszym elementem iteracji
		int smallestIndex = startIndex;

		// Wtedy szukamy najmniejszego elementu w reszcie tablicy
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// Jeśli znaleźliśmy element który jest mniejszy od poprzednio najmniejszego który znaleźliśmy
			if(array[currentIndex] < array[smallestIndex])
				//to śledź go 
				smallestIndex = currentIndex;
		}
		//smallestIndex jest teraz najmniejszym elementem w bieżącej tablicy
		//zamieniamy nasz początkowy element z naszym najmniejszym elementem 
		
		std::swap(array[startIndex], array[smallestIndex]);
	}
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';
	return 0;
}

int main()
{
	const int length = 5;
	int array[length]{ 30, 50, 20 ,10 ,40 };

	std::sort(array, array + length);

	for (int i = 0; i < length; ++i)
		std::cout << array[i];

}

int main()
{
	const int length{ 5 };
	int array[length]{ 30,50,20,10,40 };

	//step throught every element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		//smallestIndex jest indexem najmniejszego emelemntu który napotkamy w tej iteracji
		//Zaczynamy przez założenie że najmniejszy element jest pierwszym elementem iteracji
		int biggestIndex = startIndex;

		// Wtedy szukamy najmniejszego elementu w reszcie tablicy
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// Jeśli znaleźliśmy element który jest mniejszy od poprzednio najmniejszego który znaleźliśmy
			if (array[currentIndex] > array[biggestIndex])
				//to śledź go 
				biggestIndex = currentIndex;
		}
		//smallestIndex jest teraz najmniejszym elementem w bieżącej tablicy
		//zamieniamy nasz początkowy element z naszym najmniejszym elementem 

		std::swap(array[startIndex], array[biggestIndex]);
	}
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';
	return 0;
}
*/
int main()
{
	const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	 
	for (int startIndex = 0; startIndex < length ; ++startIndex)
	{

		bool swapped(false);

		int endOfArrayIndex(length - startIndex);

		for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
		{

			if (array[currentIndex] > array[currentIndex + 1])
			{
				std::swap(array[currentIndex], array[currentIndex + 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			std::cout << "Early Termination at " << startIndex + 1 << " iteration " << std::endl;
				break;
		}
	}
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';
	return 0;


}

