/** OOP3200. F2020. StandardDeck.h
 *
 *  In this lab you will create your own collection class called StandardDeck, which
 *	will 'contain' objects of the PlayingCard class.  The intent of the class is to
 *	represent a standard deck of 52 cards that might be useful in a card game type
 *	application.  
 *
 *	@author		Thom MacDonald
 *	@author		Tom Tsiliopoulos
 *	@version	2020.10
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include <vector>
#include "PlayingCard.h"

class StandardDeck
{
public:
	//Initialization:
	StandardDeck(); //default constructor
	virtual void Initialize(); //populate the deck with 52 cards

	//Rule of three:
	~StandardDeck(); //destructor
	StandardDeck(StandardDeck& other_deck); //copy constructor
	StandardDeck& operator=(StandardDeck& other_deck); //assignment operator

	//Accessors:
	int CardsRemaining(); //shows number of remaining cards
	void ShowDeck(); //displays each card in the deck

	//Mutators:
	void SetDeck(std::vector<PlayingCard> other_deck); //sets a deck (meant for copy constructor and assignment operator)
	void DrawNextCard(); //draws (shows) the card at position [0] and then removes it from the deck
	void DrawRandomCard(); //draws (shows) a card at a random position and then removes it from the deck
	void Shuffle(); //rearranges positions of cards randomly

private:
	PlayingCard* ptr; //pointer that checks if deck has any data (cards)
	std::vector<PlayingCard> deck; //the deck of cards
};

#endif /* defined (__STANDARD_DECK__) */

