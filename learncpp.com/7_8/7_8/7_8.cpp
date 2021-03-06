// 7_8.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <functional>


int add(int a, int b)
{
	return a + b;
}
int subtract(int a, int b)
{
	return a - b;
}
int multiply(int a, int b)
{
	return a * b;
}
int divide(int a, int b)
{
	return a / b;
}
char getOperator()
{
	char op;
	do
	{
		std::cout << "Enter a operator ('+', '-', '*', '/')\n";
		std::cin >> op;
	} while (op !='+' && op != '-' && op != '*' && op != '/');
	return op;
}
int getNumber(int num)
{
	int userInput;
	std::cout << "Enter a #" << num << " :\n";
	std::cin >> userInput;
	return userInput;
}

typedef int(*arithmeticFcn) (int, int);



struct arithmeticStruct
{
	char op;
	arithmeticFcn fcn;
};

static const arithmeticStruct arithmeticArray[]
{
{ '+', add },
{ '-', subtract },
{ '*', multiply },
{ '/', divide },
};
arithmeticFcn getArithmeticFunction(char op)
{
	for (const auto &arith : arithmeticArray)
	{
		if (arith.op == op)
		{
			return arith.fcn;
		}
		
	}
	return add;
}
int main()
{

	int x = getNumber(1);
	int y = getNumber(2);
	char op = getOperator();
	arithmeticFcn fcn = getArithmeticFunction(op);
	std::cout << x << " " << op << " " << y << " = " << fcn(x, y) << '\n';

    return 0;
}

