#pragma once
#include "Deck.h"

class GeneralPlayer
{
public:
	GeneralPlayer(int pID);

	void DisplayHand();

	int GetPlayerID() const { return playerID_; }
private:
	void AddToHand(const Card& card);
	void ClearHand() { hand_.clear(); }

	friend class Dealer;

	int playerID_ = 0;
	int playerCount_ = 0;

	std::vector<Card> hand_;

};

