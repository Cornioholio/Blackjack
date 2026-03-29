#pragma once
#include "Deck.h"

class GeneralPlayer
{
public:
	GeneralPlayer(int pID);

	void AddToHand(const Card& card) { hand_.push_back(card); }

	void DisplayHand();
private:
	int playerID_ = 0;
	int playerCount_ = 0;

	std::vector<Card> hand_;

};

