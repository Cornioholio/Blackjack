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
	void WaitingForBets();
	void Update();

private:
	Deck deck_;
	std::vector<Player> players_;

	GameState currentState_;
};

