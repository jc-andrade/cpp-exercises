// Member-function definitions for class DeckOFCards that simulates the shuffling and dealing of a deck of playing cards


#include <iostream>
#include <iomanip>
#include "DeckOfCards.h"
using namespace std;

// no-argument constructor
DeckOfCards::DeckOfCards()
{
	for (int i = 0; i < numberOfCards; ++i)
	{
		deck[i].face = i % faces; // faces in order
		deck[i].suit = i / faces; // suits in order
		deck[i].color = i / (faces * colors); // colors in order
	} // end for
} // end constructor

// deal cards
void DeckOfCards::deal()
{
	for (int k1 = 0, k2 = k1+numberOfCards / 2;
			k1 < numberOfCards /2 - 1; ++k1, ++k2)
		cout << "Card: " << setw(3) << deck[k1].face
		<<	"Suit: " << setw(3) << deck[k1].suit
		<<	"Color: " << setw(2) << deck[k1].color
		<< "   " << "Card: " << setw(3) <<deck[k2].face
		<<	"Suit: " << setw(2) << deck[k2].suit
		<<	"COlor: " << setw(2) << deck[k2].color << endl;
}// End function deal
