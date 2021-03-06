// 3_8.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

int main()
{
			//Definiujemy kilka fizycznych i emocjonalnych stanów
	const unsigned char isHungry = 1 << 0;
	const unsigned char isSad = 1 << 1;
	const unsigned char isMad = 1 << 2;
	const unsigned char isHappy = 1 << 3;
	const unsigned char isLaughting = 1 << 4;
	const unsigned char isAsleep = 1 << 5;
	const unsigned char isDead = 1 << 6;
	const unsigned char isCrying = 1 << 7;

	unsigned char me = 0; //all flags/options turned off start
	me |= isHappy | isLaughting; // jestem szczęśliwy i śmieje się
	me &= ~isLaughting; // nie śmieje się dłużej

	//Zakolejkuj kilka statusów (Uzyjemy statistic_cast<bool> do zinterpretowania wyniku typu bool lepiej niż integer)
	std::cout << "Jestem szczęśliwy? " << static_cast<bool>(me & isHappy) << std::endl;
	std::cout << "Śmieje się ?" << static_cast<bool>(me & isLaughting) << std::endl;

    return 0;
}

