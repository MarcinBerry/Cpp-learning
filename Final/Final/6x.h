#pragma once
#ifndef X6_H
#define X6_H
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

enum Items
{
	ITEM_POTION,
	ITEM_TORCHES,
	ITEM_ARROWS,
	MAX_ITEMS
};
struct Student
{
	std::string name;
	int grade;
};
int countTotalItems(int *items);
void sort(Student *students, int length);


enum CardRanks
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANK
};
enum CardSuits
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUIT
};
struct Card
{
	CardRanks rank;
	CardSuits suit;
};

#endif