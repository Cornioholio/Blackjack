#include "Dealer.h"
float Dealer::ReturnRewards(Player& player) 
{
	// In the future, when GameManager is in, take in the odds for the current game and return appropriate reward.
	return player.GetBet() * 2;
}
void Dealer::DealPlayerCard(Player& player, Deck& deck) 
{
	player.AddToHand(deck.DrawCard());
}
void Dealer::DealDealerCard(Deck& deck, bool faceUp) 
{
	Card card = deck.DrawCard();
	card.isFaceUp = faceUp;
	AddToHand(card);
}