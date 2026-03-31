#pragma once
#include "GeneralPlayer.h"
#include "Player.h"
class Dealer : public GeneralPlayer
{
public:
	Dealer(int pID) : GeneralPlayer(pID) {}
	Dealer() = default;

	float ReturnRewards(Player& player);
	
	void DealPlayerCard(Player& player, Deck& deck);
	void DealDealerCard(Deck& deck);
private:
	
};

