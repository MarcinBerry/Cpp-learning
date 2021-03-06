// 12.1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string m_name;
	std::string m_sound;
	Animal(std::string name)
		: m_name(name)
	{
	}
public:
	std::string getName() { return m_name; }
	const std::string speak() { return m_sound; }
};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name) { m_sound = "Meow"; }
};

class Dog : public Animal
{
public:
	Dog(std::string name) : Animal(name) {}

	const char* speak() { return "Woof"; }
};

int main()
{
	Cat fred("Fred"), misty("Misty"), zeke("Zeke");
	Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");

	Animal *animals[] = { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
	for (int iii = 0; iii < 6; iii++)
		std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << "\n";

    return 0;
}

