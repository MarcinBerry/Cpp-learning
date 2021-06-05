// 6_x1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
enum ItemType
{
	HEALTH_POTIONS,
	TORCHS,
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
	return totalItems;
}
int main()
{
	int items[]{ 2,5,10 };

	std::cout << countTotalItems(items);
    return 0;
}

