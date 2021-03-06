// 5_3.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>
/*
int getInput()
{
	std::cout << "Enter a number: " << std::endl;
	int x;
	std::cin >> x;
	return x;
}
int calculate(int first, int second)
{
	std::cout << "Enter a mathematical operator (+, -, *, /, or %): " << std::endl;
	char op;
	std::cin >> op;

	switch (op)
	{
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	case '/':
		return first / second;
	case '%':
		return first % second;
	default:
	std::cout << "Invalid operator" << std::endl;
	}
}
int main()
{
	int first = getInput();
	int second = getInput();

	int result = calculate(first, second);

	std::cout << "Result: " << result << std::endl;

    return 0;
}

*/


enum class Animal
{
	PIG,
	GOAT,
	CHICKEN,
	CAT,
	DOG,
	OSTRICH
};

std::string getAnimalName(Animal animal)
{
	switch (animal)
	{
		case Animal::PIG:
			return "pig";
		case Animal::GOAT:
			return "goat";
		case Animal::CHICKEN:
			return "chicken";
		case Animal::CAT:
			return "cat";
		case Animal::DOG:
			return "dog";
		case Animal::OSTRICH:
			return "ostrich";
		default: 
			return "invalid animal";
	}
}
void printNumberOfLegs(Animal animalType)
{
	std::cout << "A " << getAnimalName(animalType) << " has ";

	switch (animalType)
	{
	case Animal::CHICKEN:
	case Animal::OSTRICH:
		std::cout << 2 << " legs" << std::endl;
		break;
	case Animal::GOAT:
	case Animal::CAT:
	case Animal::DOG:
	case Animal::PIG:
		std::cout << 4 << " legs" << std::endl;
		break;
	}
}

int main()
{
	printNumberOfLegs(Animal::CAT);
	printNumberOfLegs(Animal::CHICKEN);

	return 0;
}