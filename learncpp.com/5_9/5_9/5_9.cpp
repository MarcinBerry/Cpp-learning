// 5_9.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()
#include <random>

/*
int main()
{
	//std::srand(static_cast<unsigned int>(std::time(0)));
	std::srand(0);
	for (int count = 1; count <= 100; ++count)
	{
		std::cout << std::rand() << "\t";

		if (count % 5 == 0)
			std::cout << "\n";

	}
    return 0;
}
*/
int main()
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	std::uniform_int_distribution<> die(1, 6);

	for (int count = 1; count <= 48; ++count)
	{
	std::cout << die(mersenne) << std::endl;

		if (count % 6 == 0)
			std::cout << std::endl;
	}
	return 0;
}
