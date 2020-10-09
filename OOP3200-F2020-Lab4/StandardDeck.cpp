//Name:             Ahmed Butt, Muzhda Ehsan
//Student ID:       100770449, 100770164
//Last Modified:    October 7, 2020
//File:				OOP3200-F2020-Lab4

#include "StandardDeck.h"
#include <ctime>
#include <iostream>

StandardDeck::StandardDeck() : created(false)
{
	Initialize();
}

void StandardDeck::Initialize()
{
	PlayingCard card;
	int suit = 0, rank = 1;

	if (created == true)
	{
		cards.clear();
	}

	for (int i = 0; i < 52; i++)
	{
		card = PlayingCard(rank, suit, i, true);
		cards.push_back(card);
		rank++;

		if (rank == 14)
		{
			suit++;
			rank = 1;
		}
	}
	created = true;
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
	return cards.size();
}

void StandardDeck::ShowDeck()
{
	for (int i = 0; i <= cards.size() - 1; i++)
	{
		std::cout << i + 1 << " " << cards[i].GetRank() << " of " << cards[i].GetSuit() << "\n";
	}
}

void StandardDeck::SetDeck(std::vector<PlayingCard> deck)
{
	for (int i = 0; i <= CardsRemaining(); i++)
	{
		cards[i] = deck[i];
	}
}

void StandardDeck::DrawNextCard()
{
	std::cout << cards[0].GetRank() << " of " << cards[0].GetSuit();
	cards.erase(cards.begin());
}

void StandardDeck::DrawRandomCard()
{
	srand(time(NULL));
	int random = rand() % cards.size();
	std::cout << cards[random].GetRank() << " of " << cards[random].GetSuit();
	cards.erase(cards.begin() + random);
}

void StandardDeck::Shuffle()
{
	srand(time(NULL));
	for (int i = 0; i <= cards.size(); i++)
	{
		int random1 = rand() % cards.size();
		int random2 = rand() % cards.size();
		
		std::swap(cards[random1], cards[random2]);
	}
}
