// 4_x.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <iostream>

	
enum class MonsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};
struct Monster
{
	MonsterType type;
	std::string name;
	int health;
};
std::string getMonsterTypeString(Monster monster)
{
	if (monster.type == MonsterType::OGRE)
		return "Ogre";
	if (monster.type == MonsterType::DRAGON)
		return "Dragon";
	if (monster.type == MonsterType::ORC)
		return "Orc";
	if (monster.type == MonsterType::GIANT_SPIDER)
		return "Gigant Spider";
	if (monster.type == MonsterType::SLIME)
		return "Slime";

	return "Unknow";
}

void printMonster(Monster monster)
{
	std::cout << "This " <<  getMonsterTypeString(monster) << " is named " << monster.name << " and has " << monster.health << " health." << std::endl;
}
int main()
{
	Monster ogre{ MonsterType::OGRE, "Torq", 145 };
	Monster slime{ MonsterType::SLIME, "Blurg", 23 };

	printMonster(ogre);
	printMonster(slime);
    return 0;
}

