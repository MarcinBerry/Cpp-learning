// 11.x2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
public:
	Creature(std::string name, char symbol, int health, int damage, int gold)
		: m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold) 
	{
	}
	
	void reduceHealth(int x) { m_health -= x; }
	bool isDead() { return m_health <= 0; }
	void addGold(int x) { m_gold += x; }
	//getters 
	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }
};

class Player : public Creature
{
protected: 
	int m_level;

public:
	Player(std::string name) : Creature(name, '@', 10, 1, 0) { m_level = 1; }
	
	void levelUp()
	{
		++m_level;
		++m_damage;
	}
	int getLevel() { return m_level; }
	bool hasWon() { return m_level >= 20; }
};

class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	struct MonsterData
	{
		std::string  m_name;
		char m_symbol;
		int m_health;
		int m_damage;
		int m_gold;
	};
	static MonsterData monsterData[MAX_TYPES];
	Type m_type;

	Monster(Type type) 
		: Creature(monsterData[type].m_name, monsterData[type].m_symbol, monsterData[type].m_health, monsterData[type].m_damage, monsterData[type].m_gold) {}

	static Monster getRandomMonster()
	{
		int num = getRandomNumber(0, MAX_TYPES - 1);
		return Monster(static_cast<Type>(num));
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};
void attackMonster(Player &p, Monster &m)
{
	if (p.isDead())
		return;

	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
	m.reduceHealth(p.getDamage());
	if (m.isDead())
	{
		std::cout << "You killed " << m.getName() << ".\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}
void attackPlayer(Player &p, Monster &m)
{
	if (m.isDead())
		return;
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
	p.reduceHealth(m.getDamage());
}
void fightMonster(Player &p)
{
	Monster monster = Monster::getRandomMonster();
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

	while (!p.isDead() && !monster.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char choose;
		std::cin >> choose;

		if (choose == 'f' )
		{
			attackMonster(p, monster);
		}
		else if ((choose == 'r') && ((getRandomNumber(0, 100)) <= 50))
		{
			std::cout << "You successfully flee.\n";
			return;
		}
		else
		{
			std::cout << "You failed to flee.\n";
		}
		if(!(monster.isDead()))
			attackPlayer(p, monster);
	}
}
int main()
{

	//starting rand
	srand(static_cast<unsigned int>(time(0)));
	rand();

	//Creating a Player
	std::string name;
	std::cout << "Enter your name ";
	std::cin >> name;
	Player player(name);
	std::cout << "Welcome, " << player.getName() << "\n";

	//starting game
	do
	{
		fightMonster(player);
		if (player.isDead())
		{
			std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
			return 0;
		}
		else if (player.hasWon())
		{
			std::cout << "You won with " << player.getGold() << " gold.\n";
			return 1;
		}

	} while (true);
}

