// 8_33.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
class Stack
{
private:
	int length{ 0 };	
	int array[10];
	

public:
	void reset()
	{
		length = 0;
		for (int i{ 0 }; i < 10; ++i)
			array[i] = 0;
	}
	bool push(int value)
	{
		if (!(length == 9))
		{
			array[length] = value;
			++length;
			return true;
		}
		else
			return false;

	}
	int pop()
	{
		assert (length > 0 && "can not pop empty stack");

		return array[--length];
	}
	void print()
	{
		std::cout << "{ ";
		for (int i{ 0 }; i < length; ++i)
			std::cout << array[i] << " ";
		std::cout << " }\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();
	
	stack.pop();
	stack.pop();

	stack.print();

    return 0;
}

