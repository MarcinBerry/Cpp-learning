// 4_5a.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	enum class Color
	{
		RED,
		BLUE
	};

	enum class Fruit
	{
		BANANA, 
		APPLE
	};

	Color color = Color::BLUE;
	Fruit fruit = Fruit::BANANA;

	//if (color == Color::RED)
	//	std::cout << "color is red\n";
	//else if (color == Color::BLUE)
	//	std::cout << "color is blue\n";

	
	std::cout << static_cast<int>(color);

	using int = error_t;
	error_t printData();
    return 0;
}

