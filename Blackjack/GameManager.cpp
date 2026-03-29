#include "GameManager.h"
GameManager::GameManager()
{

}

void GameManager::Update() 
{
	switch(currentState_) 
	{
	case GameState::GameSetup:
		// Initialize game rules here, number of decks etc.
		currentState_ = GameState::ShufflingCards;
		break;

	case GameState::ShufflingCards:
		// Shuffle the deck here.
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