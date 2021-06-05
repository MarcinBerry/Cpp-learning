#pragma once
#ifndef X4_H
#define X4_h
#include <string>

enum class MonsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIGANT_SPIDER,
	SLIME
};
struct Monster
{
	std::string name;
	MonsterType type;
	int health;
};

void printMonster(const Monster &m);
std::string convertToString(const Monster &m);

#endif