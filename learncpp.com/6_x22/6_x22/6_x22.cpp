// 6_x22.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <utility>

struct students
{
	std::string firstName;
	int grade;
};
void sortStudents(students *student, int length)
{
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int biggestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (student[biggestIndex].grade < student[currentIndex].grade)
				biggestIndex = currentIndex;
		}
		std::swap(student[startIndex], student[biggestIndex]);
	}
}
int main()
{
	int studentsNum;
	do
	{
		std::cout << "How many students you want to enter: ";
		std::cin >> studentsNum;
	} while (studentsNum < 1);

	students *student = new students[studentsNum];

	for (int index = 0; index < studentsNum; ++index)
	{
		std::cout << "Enter first name #" << index + 1 << " student.\n";
		std::cin >> student[index].firstName;
		std::cout << "Enter grade #" << index + 1 << " student.\n";
		std::cin >> student[index].grade;
	}

	sortStudents(student, studentsNum);

	for (int index = 0; index < studentsNum; ++index)
	{
		std::cout << student[index].firstName << " got a grade of " << student[index].grade << "\n";
	}

    return 0;
}

