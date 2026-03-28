#include "Deck.h"

int main() 
{
	Deck deck(1);

	deck.DisplayDeck();
	deck.ShuffleDeck();
	deck.DisplayDeck();
	return 0;
}