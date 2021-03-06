// 5_x_2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <random>

int generateRandom()
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	std::uniform_int_distribution<> die(1, 100);

	return die(mersenne);

}
bool playGame(int guesses, int randNumb)
{
	for (int count = 1; count <= guesses; ++count)
	{
		std::cout << "Guess #" << count << ": ";
		int guess;
		std::cin >> guess;

		if (guess > number)
			std::cout << "Your number is too high.\n";
		else if (guess < number)
			std::cout << "Your number is too low.\n";
		else
			return true;
	}

	return false;
}
bool playAgain()
{
	char ch;
	do
	{
		std::cout << "Would you play again (y/n)? ";
		std::cin >> ch;
	} while (ch != 'y' && ch != 'n');

	return (ch == 'y');
}

int main()
{
	std::cout << "Let's play a game.  I'm thinking of a number.You have 7 tries to guess what it is." << std::endl;
	const int guesses = 7;
	do
	{
		int randNumb = generateRandom();
		bool won = playGame(guesses, randNumb);
		if (won)
			std::cout << "Correct! You won this game!\n";
		else
			std::cout << "Sorry, you lose. The correct number was " << randNumb << "\n";
	} while (playAgain());

	std::cout << "Thank you for playing.\n";
    return 0;
}

