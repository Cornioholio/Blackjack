#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <cstdlib>
#include <algorithm>
#include <random>
struct Card 
{ 
	std::string suit;
	std::string faceValue;
	int numericValue;
};
class Deck
{
public:
	Deck(int noDecks);
	~Deck();

	void PopulateDeck();
	void ShuffleDeck();

	void DisplayDeck();

	Card DrawCard();
private:
	int numberOfDecks_ = 0;
	int cardsInDeck_ = 52;

	std::vector<Card> deck_ = {};

};

