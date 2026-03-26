#include "Deck.h"
Deck::Deck(int noDecks) : numberOfDecks_(noDecks)
{
	deck_.reserve(cardsInDeck_ * numberOfDecks_);
}
Deck::~Deck() 
{
	
}

void Deck::PopulateDeck() 
{
	std::vector<std::string> suits = { "Spades", "Hearts", "Clubs", "Diamonds" };
	for(const std::string& s : suits) 
	{
		for (int i = 2; i <= 10; i++)
		{
			deck_.push_back({ s, i });
			std::cout << i << s << std::endl;
		}
	}
}