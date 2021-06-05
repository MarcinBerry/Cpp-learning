// 6.12a.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>

/*
int main()
{
	const int numStudents = 5;
	int scores[numStudents]{ 97,69,58,80,20 };
	int maxScore = 0;

	for (const auto &score : scores)
	{
		if (score > maxScore)
			maxScore = score;

	}

	std::cout << "The Best score is " << maxScore;

    return 0;
}
*/
int main()
{
	const std::string names[] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	std::string userName;
	std::cout << "Enter a name: ";
	std::cin >> userName;

	bool found = false;
	for (const auto &name : names)
	{
		if (name == userName)
		{
			found = true;
			break;
		}
	}
	if (found)
		std::cout << userName << " name was found./n";
	else
		std::cout << userName << " name wasn't found./n";

	return 0;
}
