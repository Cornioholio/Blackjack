#include "GameManager.h"
GameManager::GameManager() : currentState_(GameState::GameSetup), dealer_(0), deck_(0)
{

}
void GameManager::GameSetup()
{
	std::cout << "Welcome to Blackjack!" << std::endl;

	int numDecks = InputUtils::GetValidatedIntInput("Enter number of decks to use (1-8): ", 1, 8);
	deck_ = Deck(numDecks);
	deck_.PopulateDeck();

	players_.clear();
	int numPlayers = InputUtils::GetValidatedIntInput("Enter number of players (1-7): ", 1, 7);
	for(int i = 1; i <= numPlayers; i++) 
	{
		players_.emplace_back(i);
	}

	std::cout << "Game setup complete. Starting game..." << std::endl;
	//return;
}
void GameManager::Update() 
{
	switch(currentState_) 
	{
	case GameState::GameSetup:
		// Initialize game rules here, number of decks etc.
		GameSetup();
		currentState_ = GameState::ShufflingCards;
		break;

	case GameState::ShufflingCards:
		// Shuffle the deck here.
		deck_.ShuffleDeck();
		std::cout << "Deck shuffled." << std::endl;
		currentState_ = GameState::WaitingForBets;
		break;

	case GameState::WaitingForBets:
		// Wait for players to place their bets.
		for(auto& player : players_) 
		{
			float bet = InputUtils::GetValidatedInput("Player " + std::to_string(player.GetPlayerID()) + ", place your bet (1 - 1000): ", 1, 1000);
			player.PlaceBet(bet);
		}
		currentState_ = GameState::DealingInitialCards;
		break;

	case GameState::DealingInitialCards:
		// Deal initial cards to players and dealer.
		dealer_.DealDealerCard(deck_, true); // Deal one face-up card to dealer.
		dealer_.DealDealerCard(deck_, false); // Deal one face-down card to dealer.
		dealer_.DisplayHand();
		for(auto& player : players_) 
		{
			dealer_.DealPlayerCard(player, deck_);
			dealer_.DealPlayerCard(player, deck_);
			player.DisplayHand();
		}
		currentState_ = GameState::PlayerTurn;
		break;

	case GameState::PlayerTurn:
		// Handle player's turn.
		for(auto& player : players_) 
		{
			player.DisplayHand();
			while(true) 
			{
				int action = InputUtils::GetValidatedInput("Player " + std::to_string(player.GetPlayerID()) + ", Hit or Stand? (0/1): ", 0, 1);
			}
		}
		currentState_ = GameState::DealerTurn;
		break;

	case GameState::DealerTurn:
		// Handle dealer's turn.
		currentState_ = GameState::ResolvingBets;
		break;

	case GameState::ResolvingBets:
		// Resolve bets and determine winners.
		currentState_ = GameState::ShufflingCards;
		break;
	}
}