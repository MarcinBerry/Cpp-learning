// 18,1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;

	char strBuff[11];

	cin.getline(strBuff, 11);
	cout << strBuff << endl;

	cin.getline(strBuff, 11);
	cout << strBuff << endl;

    return 0;
}

