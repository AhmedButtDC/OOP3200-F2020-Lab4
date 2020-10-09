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
	StandardDeck();
	virtual void Initialize();

	//Rule of three:
	~StandardDeck();
	StandardDeck(StandardDeck& other_deck);
	StandardDeck& operator=(StandardDeck& other_deck);

	//Accessors:
	int CardsRemaining();
	void DrawNextCard();
	void DrawRandomCard();
	void ShowDeck();

	//Mutators:
	void SetDeck(std::vector<PlayingCard> deck);
	void Shuffle();

private:
	bool created;
	std::vector<PlayingCard> cards;
};

#endif /* defined (__STANDARD_DECK__) */

