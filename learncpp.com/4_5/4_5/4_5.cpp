// 4_5.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>

/*
enum ItemType
{
	ITEMTYPE_SWORD,
	ITEMTYPE_TORCH,
	ITEMTYPE_POTION
};

std::string getItemName(ItemType itemType)
{
	if (itemType == ITEMTYPE_SWORD)
		return std::string("Sword");
	if (itemType == ITEMTYPE_TORCH)
		return std::string("Torch");
	if (itemType == ITEMTYPE_POTION)
		return std::string("Potion");
	
	return std::string("???");
}

int main()
{
	ItemType itemType = ITEMTYPE_TORCH;

	std::cout << "You are carrying a " << getItemName(itemType) << std::endl;


    return 0;
}
*/
enum MonsterRace
{
	MONSTERRACE_ORC,
	MOSTERRACE_GOBLIN,
	MOSTERRACE_TROLL,
	MONSTERRACE_OGRE,
	MOSTERRACE_SKELETON
};

int main 
{
	MonsterRace eMonsterRace = MONSTERRACE_TROLL;


	return 0;
}
