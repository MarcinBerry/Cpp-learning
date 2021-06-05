#include "stdafx.h"
#include <iostream>

void doSomething()
{
#define PRINT
#ifdef PRINT
	std::cout << "Printing!";
#endif
#ifndef PRINT
	std::cout << "Not Printing!";
#endif
}