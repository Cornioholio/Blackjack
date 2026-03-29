#pragma once
#include "GeneralPlayer.h"

class Player : public GeneralPlayer
{
public: 
	Player(int pID) : GeneralPlayer(pID) {}

	void PlaceBet(int amount) { bet_ = amount; }

	int GetBet() const { return bet_; }
private:
	int bet_;
};

