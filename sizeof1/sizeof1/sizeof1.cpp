// sizeof1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	//double d{ 5.0 };
	//std::cout << sizeof(d);
	//int x{ 7 }, y{ 4 };
	//std::cout << ((x > y) ? x : y);
	bool inBigClassroom = false;
	//const int classSize = inBigClassroom ? 30 : 20;
	
	if (inBigClassroom)
		const int classSize = 30;
	else
		const int clssSize = 20;
	std::cout << "The class size is : " << classSize << std::endl;
    return 0;

}

