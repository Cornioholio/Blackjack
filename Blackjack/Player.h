#pragma once
#include "GeneralPlayer.h"

class Player : public GeneralPlayer
{
public: 
	Player(int pID) : GeneralPlayer(pID) {}
	
	void PlaceBet(float amount) { bet_ = amount; }
	float GetBet() const { return bet_; }
private:
	float bank_ = 0;
	float bet_ = 0;

};

