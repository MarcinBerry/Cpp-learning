// 8_2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

class IntPair
{
public:
	int m_one;
	int m_two;

	void set(int a, int b)
	{
	m_one = a;
	m_two = b;
	}
	void print()
	{
		std::cout << "Pair(" << m_one << ", " << m_two << ")" << "\n";
	}
};
int main()
{
	IntPair p1;
	p1.set(1, 1);

	IntPair p2{ 2,2 };

	p1.print();
	p2.print();
    return 0;
}

