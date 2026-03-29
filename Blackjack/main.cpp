#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

int main() 
{
	Deck deck(1);

	Player player(0);
	Dealer dealer(1);

	deck.DisplayDeck();
	deck.ShuffleDeck();
	deck.DisplayDeck();

	dealer.DealPlayerCard(player, deck);

	player.DisplayHand();
	deck.DisplayDeck();
	return 0;
}