// ConsoleApplication1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	//ask for first integer
	std::cout << "Enter a integer: " << std::endl;
	int smaller;	//creating smaller value
	std::cin >> smaller;

	//ask for larger second integer
	std::cout << "Enter a larger integer: " << std::endl;
	int larger;		//creating larger value
	std::cin >> larger;
	
	if (smaller > larger)
	{
		//swaping values 
		int temp = smaller;
		smaller = larger;
		larger = temp;

	}
	std::cout << "The smaller value is " << smaller << std::endl;
	std::cout << "The larger value is " << larger << std::endl;
    return 0;
}

