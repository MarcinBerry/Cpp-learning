// 6.9a.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "utility"

void sortingArray(std::string *names, int length)
{
	for (int startIndex = 0; startIndex < length - 1; startIndex++)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
		{
			if (names[currentIndex] < names[smallestIndex])
			{
				smallestIndex = currentIndex;
			}
		}
		std::swap(names[startIndex], names[smallestIndex]);
	}
}

int main()
{
	std::cout << "How many names you want enter: " << std::endl;
	int length;
	std::cin >> length;

	std::string *names = new std::string[length];

	for (int i = 0; i < length; i++)
	{
		std::cout << "Enter names #" << i + 1 << std::endl;
		std::cin >> names[i];
	}

	sortingArray(names, length);

	std::cout << "Sorted names ";

	for (int ii = 0; ii < length; ii++)
	{
		std::cout << "Name #" << ii + 1 << " : " << names[ii] << std::endl;
	}
    return 0;
}

