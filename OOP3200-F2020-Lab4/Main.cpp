#include <ctime>
#include <iostream>
#include "StandardDeck.h"

void Pause() 
{
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator

	// create a deck
	StandardDeck deck;
	std::cout << "A Deck Has Been Created\n-----------------------\n";

	// Show the deck object as initialized
	deck.ShowDeck();
	Pause();

	// Draw the next card and show it
	std::cout << "Drawing Next Card\n-----------------------\n";
	deck.DrawNextCard();
	std::cout << "\n";
	Pause();

	// Draw a random card and show it
	std::cout << "Drawing Random Card\n-----------------------\n";
	deck.DrawRandomCard();
	std::cout << "\n";
	Pause();

	// Show the deck with the remaining cards
	std::cout << "Showing Remaining Cards\n-----------------------\n";
	deck.ShowDeck();
	Pause();

	// Shuffle the deck and show the result
	std::cout << "Shuffling the Deck\n-----------------------\n";
	deck.Shuffle();
	deck.ShowDeck();
	Pause();

	// Reset the deck and show the result
	std::cout << "Resetting the Deck\n-----------------------\n";
	deck.Initialize();
	deck.ShowDeck();
}


