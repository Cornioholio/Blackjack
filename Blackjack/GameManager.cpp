#include "GameManager.h"
GameManager::GameManager() : currentState_(GameState::GameSetup)
{

}
void GameManager::GameSetup()
{
	Dealer dealer(0);

	int numDecks = InputUtils::GetValidatedIntInput("Enter number of decks to use (1-8): ", 1, 8);
	Deck deck(numDecks);

	players_.clear();
	int numPlayers = InputUtils::GetValidatedIntInput("Enter number of players (1-7): ", 1, 7);
	for(int i = 1; i <= numPlayers; i++) 
	{
		players_.emplace_back(i);
	}
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
		currentState_ = GameState::WaitingForBets;
		break;

	case GameState::WaitingForBets:
		// Wait for players to place their bets.
		currentState_ = GameState::DealingInitialCards;
		break;

	case GameState::DealingInitialCards:
		// Deal initial cards to players and dealer.
		currentState_ = GameState::PlayerTurn;
		break;

	case GameState::PlayerTurn:
		// Handle player's turn.
		currentState_ = GameState::DealerTurn;
		break;

	case GameState::DealerTurn:
		// Handle dealer's turn.
		currentState_ = GameState::ResolvingBets;
		break;

	case GameState::ResolvingBets:
		// Resolve bets and determine winners.
		currentState_ = GameState::GameSetup;
		break;
	}
}