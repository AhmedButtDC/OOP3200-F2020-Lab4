//Name:             Ahmed Butt, Muzhda Ehsan
//Student ID:       100770449, 100770164
//Last Modified:    October 9, 2020
//File:				OOP3200-F2020-Lab4

#include "StandardDeck.h"
#include <ctime>
#include <iostream>

//Default Constructor
StandardDeck::StandardDeck() : ptr(0)
{
	Initialize(); //used to populate deck vector
}

//Initialize the deck (put 52 cards together to create a deck)
void StandardDeck::Initialize()
{
	PlayingCard card;
	int suit = 0, rank = 1;
	const int maxCards = 52;

	if (ptr != 0) //if pointer has no data, deck is empty
	{
		deck.clear(); //clear deck if not empty
	}

	for (int i = 0; i < maxCards; i++) //this loop creates the deck of 52 cards
	{
		card = PlayingCard(rank, suit, i, true);
		deck.push_back(card);
		rank++;

		if (rank == 14)
		{
			suit++;
			rank = 1;
		}
	}
	ptr = deck.data(); //deck is created, so pointer must not be 0
}

//Destructor
StandardDeck::~StandardDeck()
= default;

//Copy Constructor
StandardDeck::StandardDeck(StandardDeck& other_deck)
{
	SetDeck(other_deck.deck);
}

//Assignment Operator
StandardDeck& StandardDeck::operator=(StandardDeck& other_deck)
{
	SetDeck(other_deck.deck);
	return *this;
}

//CardsRemaining() - returns the current size of deck
int StandardDeck::CardsRemaining()
{
	return deck.size();
}

//ShowDeck() - displays all cards in the deck
void StandardDeck::ShowDeck()
{
	for (int i = 0; i <= deck.size() - 1; i++)
	{
		std::cout << i + 1 << " " << deck[i].GetRank() << " of " << deck[i].GetSuit() << "\n";
	}
}

//SetDeck() - sets all cards of the deck to another deck
void StandardDeck::SetDeck(std::vector<PlayingCard> other_deck)
{
	for (int i = 0; i <= CardsRemaining(); i++)
	{
		deck[i] = other_deck[i];
	}
}

//DrawNextCard() - displays the card that will be removed and then removes it
void StandardDeck::DrawNextCard()
{
	std::cout << deck[0].GetRank() << " of " << deck[0].GetSuit();
	deck.erase(deck.begin());
}

//DrawRandomCard() - gets a random number, uses it to pick a random card, display it, and then removes that card
void StandardDeck::DrawRandomCard()
{
	srand(time(NULL));
	int random = rand() % deck.size();
	std::cout << deck[random].GetRank() << " of " << deck[random].GetSuit();
	deck.erase(deck.begin() + random);
}

//Shuffle() - gets 2 random numbers, uses them to swap a random card with another random card in a loop that loops
//an amount of times equal to the size of the deck
void StandardDeck::Shuffle()
{
	srand(time(NULL));
	for (int i = 0; i <= deck.size(); i++)
	{
		int random1 = rand() % deck.size();
		int random2 = rand() % deck.size();
		
		std::swap(deck[random1], deck[random2]);
	}
}
