// 4_4b.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <iostream>

int main()
{
	/*
	std::cout << "Enter yout full name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "ENter your age: " << std::endl;
	std::string age;
	std::getline(std::cin, age);

	std::cout << "Yout full name is " << name << " and your age is " << age;
	

	std::cout << "Pick 1 or 2";
	int choice{ 0 };
	std::cin >> choice;

	std::cin.ignore(32767, '\n');

	std::cout << "Now enter you name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "Hello, " << name << ", you picked " << choice << std::endl;
	

	std::string a("45");
	std::string b("27");

	std::cout << a + b << std::endl;
	a += " volts";
	std::cout << a;
	

	std::string myName("Marcin");
	std::cout << myName << " has " << myName.length() << " character" << std::endl;
	*/

	std::cout << "Enter your full name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "Enter you age: " << std::endl;
	double age;
	std::cin >> age;


	std::cout << "You've lived " << age / (name.length()) << " years for each letter in your name." << std::endl;
    return 0;
}

