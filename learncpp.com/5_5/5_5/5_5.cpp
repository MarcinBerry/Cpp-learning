// 5_5.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>


/*
int main()
{
	/*
	int count = 0;
	while (count < 10)
	{
		std::cout << count << " ";
		++count;
	}
	std::cout << "done";
	
	unsigned int count = 10;
	while (count >= 10)
	{
		if (count == 0)
			std::cout << "blastoff";
		else
			std::cout << count << " ";
		--count;
	}
	

	int count = 1;
	int sum = 0;

	while (count <= 5)
	{
		int x;
		std::cout << "Enter integer #" << count << std::endl;
		std::cin >> x;

		sum += x;

		++count;
	}
	std::cout << "The sum of all numbers entered is: " << sum;
	
	int outter = 1;
	while (outter <= 5)
	{
		int inner = 1;
		while (inner <=outter)
		{
			std::cout << inner++ << " ";
		}
		std::cout << "\n";
		++outter;
	}
	

	char mychar = 'a';
	while (mychar <= 'z')
	{
		std::cout << mychar << " " << static_cast<int>(mychar) << "\n";
		++mychar;
	}

	

int main()
{
	int outer = 5;
	while (outer >= 1)
	{
		// loop between 1 and outer
		int inner = outer;
		while (inner >= 1)
			std::cout << inner-- << " ";
		// print a newline at the end of each row
		std::cout << "\n";			
		--outer;
	}

		return 0;
	}

*/
int main()
{
	int outer = 1;
	while (outer <= 5)
	{
		
		int inner = 5;
		while (inner >= 1)
		{
			if (inner <= outer)
				std::cout << inner << " ";
			else
				std::cout << "  ";
			inner--;
		}
		std::cout << "\n";
		++outer;
	}
	return 0;
}