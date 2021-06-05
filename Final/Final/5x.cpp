#include "pch.h"
#include "5x.h"


int getInput(int nTry)
{
	while(1)
	{
		std::cout << "Guess #" << nTry << ": ";
		int in;
		std::cin >> in;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return in;
		}
	}
}
bool checkAnswer(int input, int randNumber)
{
	if (input < randNumber)
	{
		std::cout << "Your guess is too low.\n";
		return false;
	}
	else if (input > randNumber)
	{
		std::cout << "Your guess is too high.\n";
		return false;
	}
	else
	{
		std::cout << "Correct! You win!\n";
		return true;
	}
}
bool again()
{
	std::cout << "Would You play again (y/n)?\n ";
	char s;
	std::cin >> s;
	if (s == 'y')
		return true;
	else if (s == 'n')
		return false;
	else
		return again();
}