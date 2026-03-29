#include "Dealer.h"
void Dealer::DealCard(Player& hand, Deck& deck) 
{
	hand.AddToHand(deck.DrawCard());
}