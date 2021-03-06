// 6_x2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <utility>
struct student
{
	std::string firstName;
	int grade;
};
void sortGrade(student *students, int length)
{
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int largestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (students[currentIndex].grade > students[largestIndex].grade)
				largestIndex = currentIndex;
		}
		std::swap(students[startIndex], students[largestIndex]);
	}
	
	
}
int main()
{
	int studentsNum;

	do
	{
		std::cout << "How many students you want enter :";
		std::cin >> studentsNum;
	} while (studentsNum <= 1);

	student *students = new student[studentsNum];

	for (int index = 0; index < studentsNum; ++index)
	{
		std::cout << "Enter first name for #" << index + 1 << " students." << std::endl;
		std::cin >> students[index].firstName;

		std::cout << "Enter grade for #" << index + 1 << " students." << std::endl;
		std::cin >> students[index].grade;
	}

	sortGrade(students, studentsNum);

	for (int index = 0; index < studentsNum; ++index)
	{
		std::cout << students[index].firstName << " got a grade for " << students[index].grade << std::endl;
	}

	delete[] students;
    return 0;
}

