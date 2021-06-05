#include "pch.h"
#include <string>
#include <iostream>
#include "4x.h"

enum class MonsterType;
struct Monster;

std::string convertToString(const Monster &m)
{
	switch (m.type)
	{
	case MonsterType::OGRE:			return "Ogre";
	case MonsterType::DRAGON:			return "Dragon";
	case MonsterType::ORC:			return "Orc";
	case MonsterType::GIGANT_SPIDER:	return "Gigant Spider";
	case MonsterType::SLIME:			return "Slime";
	default: return "Unknow";
	}
}
void printMonster(const Monster &m)
{
	std::cout << "This " << convertToString(m) << " is named " << m.name << " and has " << m.health << " health.\n";
}