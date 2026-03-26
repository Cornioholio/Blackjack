#pragma once
#include <vector>
#include <string>
#include <iostream>
struct Card 
{ 
	std::string suit;
	int value;
};
class Deck
{
public:
	Deck(int noDecks);
	~Deck();

	void PopulateDeck();
private:
	int numberOfDecks_ = 0;
	int cardsInDeck_ = 52;

	std::vector<Card> deck_ = {};

};

