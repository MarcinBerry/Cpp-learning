// 8_x3.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <ctime>

class Monster
{
public:
	enum MonsterType
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitPoint;

public:
	Monster(MonsterType type, std::string name, std::string roar, int hitPoint) : m_type(type), m_name(name), m_roar(roar), m_hitPoint(hitPoint) {}

	std::string getTypeString()
	{
		switch (m_type)
		{
		case MonsterType::DRAGON: return "Dragon";
		case MonsterType::GOBLIN: return "Goblin";
		case MonsterType::OGRE: return "Ogre";
		case MonsterType::ORC: return "Orc";
		case MonsterType::SKELETON: return "Skeleton";
		case MonsterType::TROLL: return "Troll";
		case MonsterType::VAMPIRE: return "Vampire";
		case MonsterType::ZOMBIE: return "Zombie";
		}
		return "???";
	}
	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoint << " hit points and says " << m_roar << "\n";
	}
};
class MonsterGenerator
{
public:

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand()*fraction*(max - min + 1) + min);
	}
	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, (static_cast<int>(Monster::MAX_MONSTER_TYPES)) - 1));
		int hitPoint = getRandomNumber(0, 100);

		std::array<std::string, 6> s_names{ "Drak", "Gob", "Og", "Ton", "Torl", "Ampi", };
		std::array<std::string, 6> s_roars{ "(Dragon sound)", "(Goblin sound)","(Ogre sound)","(Skeleton sound)","(Troll sound)","(Vampire sound)" };

		 
		return	Monster( type, s_names[getRandomNumber(0,5)], s_roars[getRandomNumber(0,5)], hitPoint );

	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}

