#include "Deck.h"
Deck::Deck(int noDecks) : numberOfDecks(noDecks)
{
	deck.reserve(cardsInDeck * numberOfDecks);
}
Deck::~Deck() 
{
	
}