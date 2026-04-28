#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include "InputUtils.h"

enum class GameState
{
	GameSetup = 0,
	ShufflingCards,
	WaitingForBets,
	DealingInitialCards,
	PlayerTurn,
	DealerTurn,
	ResolvingBets
};
class GameManager
{
public:
	GameManager();

	void GameSetup();

	void Update();

private:
	std::vector<Player> players_;
	Dealer dealer_;
	Deck deck_;


	GameState currentState_;
};

