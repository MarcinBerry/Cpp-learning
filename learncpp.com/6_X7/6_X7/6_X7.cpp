// 6_x66.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <string>
#include <array>
#include <ctime>

enum CardSuit
{
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUIT_HEARTHS,
	SUIT_SPADES,
	MAX_SUIT
};
enum CardRank
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

struct Card
{
	CardRank rank;
	CardSuit suit;
};
void printCard(const Card &card)
{
	switch (card.rank)
	{
	case	RANK_2:			std::cout << "2"; break;
	case	RANK_3:			std::cout << "3"; break;
	case	RANK_4:			std::cout << "4"; break;
	case	RANK_5:			std::cout << "5"; break;
	case	RANK_6:			std::cout << "6"; break;
	case	RANK_7:			std::cout << "7"; break;
	case	RANK_8:			std::cout << "8"; break;
	case	RANK_9:			std::cout << "9"; break;
	case	RANK_10:		std::cout << "T"; break;
	case	RANK_JACK:		std::cout << "J"; break;
	case	RANK_QUEEN:		std::cout << "Q"; break;
	case	RANK_KING:		std::cout << "K"; break;
	case	RANK_ACE:		std::cout << "A"; break;
	}
	switch (card.suit)
	{
	case	SUIT_CLUBS:		std::cout << "C"; break;
	case	SUIT_DIAMONDS:	std::cout << "D"; break;
	case	SUIT_HEARTHS:	std::cout << "H"; break;
	case	SUIT_SPADES:	std::cout << "S"; break;
	}
}

void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
	std::cout << "\n";
}
void swapCard(Card &a, Card &b)
{
	Card temp = a;
	a = b;
	b = temp;
}
int getRandom(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void shuffleDeck(std::array<Card, 52> &deck, int cards)
{
	for (int index = 0; index < cards; ++index)
	{
		int randomIndex = getRandom(0, 51);
		swapCard(deck[index], deck[randomIndex]);
	}
}
int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case	RANK_2:			return 2;
	case	RANK_3:			return 3;
	case	RANK_4:			return 4;
	case	RANK_5:			return 5;
	case	RANK_6:			return 6;
	case	RANK_7:			return 7;
	case	RANK_8:			return 8;
	case	RANK_9:			return 9;
	case	RANK_10:		return 10;
	case	RANK_JACK:		return 10;
	case	RANK_QUEEN:		return 10;
	case	RANK_KING:		return 10;
	case	RANK_ACE:		return 11;
	}
	return 0;
}
char getPlayerChoice()
{
	std::cout << "(h) to hit, (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}
bool playBlackjack(std::array<Card, 52> &deck)
{
	Card *cardptr = &deck[0];
	int playerTotal = 0; int dealerTotal = 0;

	dealerTotal += getCardValue(*cardptr++);
	std::cout << "The Dealer is showing: " << dealerTotal << '\n';

	playerTotal += getCardValue(*cardptr++);
	playerTotal += getCardValue(*cardptr++);

	while (true)
	{
		std::cout << "You have: " << playerTotal << " ";

		if (playerTotal > 21)
		{
			std::cout << "Your score: " << playerTotal << "\n";
			return false;
		}

		char choice = getPlayerChoice();
		if (choice == 's')
			break;


		playerTotal += getCardValue(*cardptr++);
		std::cout << "Your score: " << playerTotal << "\n";
	}
	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardptr++);
		std::cout << "Dealer score: " << dealerTotal << "\n";
	}
	if (dealerTotal > 21)
	{
		return true;
	}

	return (playerTotal > dealerTotal);
}
bool playAgain()
{
	std::cout << "Would you play again ? (y for yes, n fo no)";
	char again;
	while (true)
	{
		std::cin >> again;
		switch (again)
		{
		case 'y':	return true;
		case 'n':	return false;
		}
	}
}
int main()
{
	srand(static_cast<unsigned int>(time(0))); 
	rand();

	std::array<Card, 52> deck;

	int cards = 0;
	for (int suit = 0; suit < MAX_SUIT; ++suit)
		for (int rank = 0; rank < MAX_RANK; ++rank)
		{
			deck[cards].suit = static_cast<CardSuit>(suit);
			deck[cards].rank = static_cast<CardRank>(rank);
			++cards;
		}
	
	do
	{
		shuffleDeck(deck, cards);
		if (playBlackjack(deck))
			std::cout << "You win!\n";
		else
			std::cout << "You lose!\n";
	} while (playAgain());
	return 0;
}

