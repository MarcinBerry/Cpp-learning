// 5_8.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
/*
int main()
{
	int sum = 0;

	// Allow the user to enter up to 10 numbers
	for (int count = 0; count < 10; ++count)
	{
		std::cout << "Enter a number to add, or 0 to exit: ";
		int num;
		std::cin >> num;

		// exit loop if user enters 0
		if (num == 0)
			break;

		// otherwise add number to our sum
		sum += num;
	}

	std::cout << "The sum of all the numbers you entered is " << sum << "\n";

	return 0;

}


int breakOrReturn()
{
	while (true)
	{
		std::cout << "Enter 'b' to break 'r' to return:  ";
		char ch;
		std::cin >> ch;

		if (ch == 'b')
			break;

		if (ch == 'r')
			return 1;
	}
	std::cout << "We broke out of the loop\n";

	return 0;
}
int main()
{
	int returnValue = breakOrReturn();
	std::cout << "function breakOrContinue returned " << returnValue << std::endl;

	return 0;
}
*/
int main()
{
	int count{ 0 };
	while (true)
	{
		std::cout << "Enter 'e' to ezit this loop pr any other character to continoue: ";
		char ch;
		std::cin >> ch;

		if (ch == 'e')
			break;
		
			++count;
			std::cout << "We've iterated " << count << " times\n";
	}
	return 0;

}