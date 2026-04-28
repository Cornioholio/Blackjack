#include "GeneralPlayer.h"
GeneralPlayer::GeneralPlayer(int pID) : playerID_(pID) 
{
	
}

void GeneralPlayer::DisplayHand() 
{
	if(playerID_ == 0) 
	{
		std::cout << "!! Dealer's hand:" << std::endl;
	}
	else 
	{
		std::cout << "!! Player " << playerID_ << "'s hand:" << std::endl;
	}

	for (const auto& card : hand_) 
	{
		card.DisplayCard();
	}
	std::cout << playerCount_ << std::endl;
}
void GeneralPlayer::AddToHand(const Card& card)
{
	if(card.isFaceUp) 
	{
		playerCount_ += card.numericValue;
	}
	hand_.push_back(card);
}