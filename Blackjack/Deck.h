#pragma once
#include <vector>
#include <string>
struct Card 
{ 
	std::string suit;
	int value;
};
class Deck
{
private:
	Deck(int noDecks);
	~Deck();

public:
	int numberOfDecks = 0;
	int cardsInDeck = 52;

	std::vector<Card> deck = {};

};

