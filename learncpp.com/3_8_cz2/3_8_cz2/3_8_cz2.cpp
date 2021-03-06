// 3_8_cz2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <bitset>
#include <iostream>

/*
const int option0 = 0;
const int option1 = 1;
const int option2 = 2;
const int option3 = 3;
const int option4 = 4;
const int option5 = 5;
const int option6 = 6;
const int option7 = 7;

int main()
{
	std::bitset<8> bits(0x2);
	bits.set(option4);
	bits.flip(option5);
	bits.reset(option5);
	
	std::cout << "Bit 4 has value: " << bits.test(option4) << std::endl;
	std::cout << "Bit 5 has value: " << bits.test(option5) << std::endl;
	std::cout << "All the bitts: " << bits << std::endl;

    return 0;


	const unsigned int lowMask = 0xF;

	std::cout << "Enter an integer: ";
	int num;
	std::cin >> num;

	num &= lowMask; // remove the high bits to leabe only yhe low bits

	std::cout << "The 4 low bits ahve value: " << num << std::endl;
	
	const unsigned int redBits = 0xFF000000;
	const unsigned int greenBits = 0x00FF0000;
	const unsigned int blueBits = 0x0000FF00;
	const unsigned int alphaBits = 0x000000FF;

	std::cout << "Enter a 32-bit RGBA color value in hexadecimal: " << std::endl;
	unsigned int pixel;
	std::cin >> std::hex >> pixel;

	unsigned char red = (pixel & redBits) >> 24;
	unsigned char green = (pixel & greenBits) >> 16;
	unsigned char blue = (pixel & blueBits) >> 8;
	unsigned char alpha = pixel & alphaBits;

	std::cout << "Your color contains:\n";
	std::cout << static_cast<int>(red) << " of 255 red\n";
	std::cout << static_cast<int>(green) << " of 255 green\n";
	std::cout << static_cast<int>(blue) << " of 255 blue\n";
	std::cout << static_cast<int>(alpha) << " of 255 alpha\n";
}





*/

int main()
{
	unsigned char option_viewed = 0x01;
	unsigned char option_edited = 0x02;
	unsigned char option_favorited = 0x03;
	unsigned char option_shared = 0x04;
	unsigned char option_deleted = 0x05;
	unsigned char option_myArticleFlags = 0x06;

	unsigned char myArticeFlags = 0;

	myArticleFlags |= option_viewed;
	
	if (myArticeFlags & option_deleted)
		std::cout << "Your Article was deleted" << std::endl;
	else
		std::cout << " Your Article wasn't delted" << std::endl;

	myArticleFlags &= ~option_favorited;



	return 0;
}
