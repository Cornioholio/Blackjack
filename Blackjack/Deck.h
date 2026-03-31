#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <memory>

struct Card 
{ 
	std::string suit;
	std::string faceValue;
	int numericValue;

	bool isFaceUp = true;

	void DisplayCard() const 
	{
		if(isFaceUp == false) return;
		std::cout << faceValue << " of " << suit << std::endl;
	}
};
class Deck
{
public:
	Deck(int noDecks);
	Deck() = default;

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

