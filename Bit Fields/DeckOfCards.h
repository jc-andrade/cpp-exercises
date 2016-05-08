// DeckOfCards.h
// Definiton of class DeckOFCards that represents a deck of playing cards

#include <vector>
using namespace std;

// BitCard structure definition with bit fields
struct BitCard
{
	unsigned face : 4; // 4 bits; 0-15
	unsigned suit : 2; // 2bits; 0-3
	unsigned color : 1; // 1 bit; 0-1
}; // End struct

// DeckOFCards class definition
class DeckOfCards
{
public:
	static const int faces = 13;
	static const int colors = 2; // black and red
	static const int numberOfCards = 52;

	DeckOfCards(); // constructor initializes deck
	void deal(); // deals cards

private:
	vector< BitCard > deck; // creates vector named deck representing deck of cards
};
