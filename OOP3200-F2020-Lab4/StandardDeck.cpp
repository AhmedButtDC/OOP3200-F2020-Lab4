//Name:             Ahmed Butt, Muzhda Ehsan
//Student ID:       100770449, 100770164
//Last Modified:    October 7, 2020
//File:				OOP3200-F2020-Lab4

#include "StandardDeck.h"

StandardDeck::StandardDeck() : cards(0)
{
	Initialize();
}

void StandardDeck::Initialize()
{
	int suit = 0, rank = 1;

	if (cards != 0)
	{
		delete(cards);
	}

	cards = new PlayingCard[52];

	for (int i = 0; i <= 51; i++)
	{
		cards[i].SetSuit(suit);
		cards[i].SetRank(rank);
		suit++;
		rank++;
		if (suit == 4)
		{
			suit = 0;
		}
		if (rank == 14)
		{
			rank = 0;
		}
	}
}

StandardDeck::~StandardDeck()
= default;

StandardDeck::StandardDeck(const StandardDeck& other_deck)
{
	
}

StandardDeck& StandardDeck::operator=(const StandardDeck& other_deck)
{
	
}

int StandardDeck::CardsRemaining(PlayingCard cardsRemaining[])
{
	return 0;
}

PlayingCard StandardDeck::DrawNextCard(PlayingCard cardsRemaining[])
{
	return PlayingCard();
}

void StandardDeck::Shuffle()
{

}
