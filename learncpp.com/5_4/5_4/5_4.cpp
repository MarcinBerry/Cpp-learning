// 5_4.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cmath> //for sqrt()

int main()
{
	double x;
tryAgain: //this is a statment label
	std::cout << "Enter a non-negative number";
	std::cin >> x;

	if(x < 0.0)
		goto tryAgain;	//goto statment

	std::cout << "The sqrt of " << x << " is " << sqrt(x) << std::endl;
    return 0;
}

