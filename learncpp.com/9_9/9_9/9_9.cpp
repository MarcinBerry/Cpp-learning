// 9_9.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
class Mystring
{
private:
	std::string string;

public:
	Mystring(std::string value) : string(value) {}

	int operator() (int start, int length);
};
int Mystring::operator() (int start, int length)
{

}
int main()
{
    return 0;
}

