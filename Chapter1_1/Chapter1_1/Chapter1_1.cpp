// Chapter1_1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include "io.h"


int main()
{
	int value1 = readNumber();
	int value2 = readNumber();
	writeAnswer(value1 + value2);
    return 0;
}

