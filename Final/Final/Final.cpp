#include "pch.h"

//1x
/*
#include "io.h"


int main()
{
	int x = readNumber();
	int y = readNumber();
	writeAnswer(x + y);

	return 0;
}
*/

//2x
/*
#include "2x.h"

int main()
{
	double x = readNumber();
	double y = readNumber();
	char ch = choose();

	calculate(x, y, ch);

	return 0;
}
*/

//3x
/*
#include "3x.h"
#include "constants.h"

int main()
{
	double meters = readHeight();
	int seconds = 0;
	do
	{
		
		print(calculate(meters, seconds), seconds);
		seconds++;

	} while (meters > 0);
	return 0;
}
*/

//4x

/*

#include "4x.h"


int main()
{
	Monster Ogre{ "Torq", MonsterType::OGRE, 145 };

	return 0;
}
*/

//5x
/*
#include "5x.h"
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);  
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}
int main()
{
	//start game
	do
	{
		std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.\n";
		int randNumber = getRandomNumber(0, 100);
		if (randNumber == 0)
			randNumber = getRandomNumber(25, 75);

		for (int nTry = 1; nTry <= 7; ++nTry)
		{
			bool correct = checkAnswer(getInput(nTry), randNumber);
			if (correct)
				break;
			if (nTry == 7)
				std::cout << "Sorry, you lose.The correct number was " << randNumber << "./n";
		}

	} while (again());

	return 0;
}
*/

//6x
#include "6x.h"
/*
#include <algorithm>
int main()
{
	//int items[MAX_ITEMS]{ 2,5,10 };
	//std::cout << "Total items: " << countTotalItems(items);
	int maxStudents{ 0 };
	do
	{
		std::cout << "How many students would you like to create: ";
		std::cin >> maxStudents;
	} while (maxStudents <= 1);

	Student *students = new Student[maxStudents];

	for (int index{ 0 }; index < maxStudents; ++index)
	{
		std::cout << "Name of #" << index + 1 << " student: ";
		std::cin >> students[index].name;
		std::cout << "Grade of #" << index + 1 << " student: ";
		std::cin >> students[index].grade;
	}
	sort(students, maxStudents);

	for (int index{ 0 }; index < maxStudents; ++index)
	{
		std::cout << students[index].name << " got a grade of " << students[index].grade << "\n";
	}
	delete[] students;
	return 0;
}
*/

int main()
{
	std::array<Card, 52> deck;

	for (int suit{ 0 }; suit < MAX_SUIT; ++suit)
	{
		for (int rank{ 0 }; rank < MAX_RANK; ++rank)
		{
			deck[rank].rank = static_cast<CardRanks>(rank);
			deck[suit].suit = static_cast<CardSuits>(suit);
		}
	}
	return 0;
}