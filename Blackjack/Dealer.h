#pragma once
#include "GeneralPlayer.h"
#include "Player.h"
class Dealer : public GeneralPlayer
{
public:
	Dealer(int pID) : GeneralPlayer(pID) {}

	void DealCard(Player& hand, Deck& deck);
private:
	
};

