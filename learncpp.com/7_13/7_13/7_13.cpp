// 7_13.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

/*
int main(int argc, char *argv[])
{
	std::cout << "There are " << argc << " arguments:\n";

	for (int count = 0; count < argc; ++count)
		std::cout << count << " " << argv[count] << "\n";
    return 0;
}
*/

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << "\n";
		else
			std::cout << "Usage: <program name> <numbers>\n";

		exit(1);	
	}

	std::stringstream convert(argv[1]);

	int myint;
	if (!(convert >> myint))
		myint = 0;
	std::cout << "Got integer: " << myint << "\n";

	return 0;
}