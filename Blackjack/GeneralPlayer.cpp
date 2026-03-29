#include "GeneralPlayer.h"
GeneralPlayer::GeneralPlayer(int pID) : playerID_(pID) 
{
	
}

void GeneralPlayer::DisplayHand() 
{
	std::cout << "!! Player " << playerID_ << "'s hand:" << std::endl;
	for (const auto& card : hand_) 
	{
		std::cout << card.faceValue << " of " << card.suit << std::endl;
	}
}