// 6_x.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>

enum  Item_Type
{
	HEALTH_POTION,
	TORCHES,
	ARROWS,
	MAX_ITEMS
};
int countTotalItems(int *items)
{
	int totalItems = 0;
	for (int index = 0; index < MAX_ITEMS; ++index)
	{
		totalItems += items[index];
	}
	return totalItems
}
int main()
{
	int itemNum[MAX_ITEMS]{ 2,5,10 };

	std::cout << "Total number of your items is " << countTotalItems(itemNum) << std::endl;

	return 0;
}

