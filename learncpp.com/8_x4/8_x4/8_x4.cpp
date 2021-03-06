// 8_x4.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>
#include <assert.h>
class Card
{
public:
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
	enum CardSuit
	{
		SUIT_CLUBS,
		SUIT_DIAMODNS,
		SUIT_HEARTS,
		SUIT_SPADES,
		MAX_SUIT
	};

private:
	CardRank m_rank;
	CardSuit m_suit;

public:
	Card(CardRank rank = MAX_RANK, CardSuit suit = MAX_SUIT) : m_rank(rank), m_suit(suit) {};

	void printCard() const
	{
		switch (m_rank)
		{
		case RANK_2:		std::cout << "2"; break;
		case RANK_3:		std::cout << "3"; break;
		case RANK_4:		std::cout << "4"; break;
		case RANK_5:		std::cout << "5"; break;
		case RANK_6:		std::cout << "6"; break;
		case RANK_7:		std::cout << "7"; break;
		case RANK_8:		std::cout << "8"; break;
		case RANK_9:		std::cout << "9"; break;
		case RANK_10:		std::cout << "10"; break;
		case RANK_JACK:		std::cout << "J"; break;
		case RANK_QUEEN:	std::cout << "Q"; break;
		case RANK_KING:		std::cout << "K"; break;
		case RANK_ACE:		std::cout << "A"; break;
		}
		switch (m_suit) 
		{
		case SUIT_CLUBS:	std::cout << "C"; break;
		case SUIT_DIAMODNS: std::cout << "D"; break;
		case SUIT_HEARTS:	std::cout << "H"; break;
		case SUIT_SPADES:	std::cout << "S"; break;
		}
		
	}
	int getCardValue() const
	{
		switch (m_rank)
		{
		case RANK_2:		return 2;
		case RANK_3:		return 3;
		case RANK_4:		return 4;
		case RANK_5:		return 5;
		case RANK_6:		return 6;
		case RANK_7:		return 7;
		case RANK_8:		return 8;
		case RANK_9:		return 9;
		case RANK_10:		return 10;
		case RANK_JACK:		return 10;
		case RANK_QUEEN:	return 10;
		case RANK_KING:		return 10;
		case RANK_ACE:		return 11;
		}
		return 0;
	}
	friend class Deck;
};
class Deck
{
private:
	std::array<Card, 52> m_deck;
	int m_cardIndex{ 0 };

	void swapCard(Card &a, Card&b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}
	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
public:
	Deck()
	{
		int card = 0;
		for (int suit = 0; suit < Card::MAX_SUIT; ++suit)
			for (int rank = 0; rank < Card::MAX_RANK; ++rank)
			{
				m_deck[card] = Card(static_cast<Card::CardRank>(rank),static_cast<Card::CardSuit>(suit));
				++card;
			}
	}
	void printDeck()
	{
		for (auto const &card : m_deck)
		{
			card.printCard();
			std::cout << " ";
		}
		std::cout << "\n";
	}
	void shuffleDeck()
	{
		for (int index = 0; index < 52; ++index)
		{
			int swapIndex = getRandomNumber(0, 51);
			swapCard(m_deck[index], m_deck[swapIndex]);
		}
		m_cardIndex = 0;
	}
	const Card& dealCard()
	{
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	}
};
char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}
bool playBlackjack(Deck &deck)
{
	int playerTotal = 0;
	int dealerTotal = 0;

	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << "\n";

	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	while (1)
	{
		std::cout << "You have: " << playerTotal << "\n";
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();

		if (playerTotal > 21)
			return false;
	}
	while (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Deck deck;
	deck.shuffleDeck();
	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}
