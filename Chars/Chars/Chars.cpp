// Chars.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	/*
	char ch(97);
	std::cout << ch << std::endl;
	std::cout << static_cast<int>(ch) << std::endl;
	std::cout << ch << std::endl;
	
	std::cout << "Enter a keyboard chracter: ";
	char ch;
	std::cin >> ch;
	std::cout << ch << "has ASCII code " << static_cast<int>(ch) << std::endl;
	
	std::cout << "First line\nSecond line"  << std::endl;
	*/
	std::cout << "\"This is a quote text\"\n";
	std::cout << "This string contains a single backslash \\" << std::endl;
	std::cout << "6F in hex is a char \'\x6F\'" << std::endl;
    return 0;
}

