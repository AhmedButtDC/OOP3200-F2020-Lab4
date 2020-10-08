//Name:             Ahmed Butt, Muzhda Ehsan
//Student ID:       100770449, 100770164
//Last Modified:    October 7, 2020
//File:				OOP3200-F2020-Lab4

#include "StandardDeck.h"

StandardDeck::StandardDeck() : ptr(0)
{
	Initialize();
}

void StandardDeck::Initialize()
{
	int suit = 0, rank = 1;

	if (ptr != 0)
	{
		delete(cards);
	}

	for (int i = 0; i < 5; i++)
	{
		cards[i] = PlayingCard(rank, suit, i, true);
		rank++;

		if (rank == 14)
		{
			suit++;
			rank = 1;
		}
	}
}

StandardDeck::~StandardDeck()
= default;

StandardDeck::StandardDeck(StandardDeck& other_deck)
{
	SetDeck(other_deck.cards);
}

StandardDeck& StandardDeck::operator=(StandardDeck& other_deck)
{
	SetDeck(other_deck.cards);
	return *this;
}

int StandardDeck::CardsRemaining()
{
	return sizeof(cards)/16;
}

PlayingCard StandardDeck::DrawNextCard()
{
	return PlayingCard();
}

void StandardDeck::SetDeck(PlayingCard deck[])
{
	for (int i = 0; i <= 51; i++)
	{
		cards[i] = deck[i];
	}
}

void StandardDeck::Shuffle(PlayingCard deck[])
{

}
