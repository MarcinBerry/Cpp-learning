// 5_6.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int selection;

	do
	{
		std::cout << "Please make a selection: \n";
		std::cout << "1) Addition \n";
		std::cout << "2) Subtraction \n";
		std::cout << "3) Multiplication \n";
		std::cout << "4) Division \n";
		std::cin >> selection;
	} while (selection != 1 && selection != 2 && selection != 3 && selection != 4);


		std::cout << "You selected  option " << selection << std::endl;

    return 0;
}

