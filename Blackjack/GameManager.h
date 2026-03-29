#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
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

	void InitUsers();

	void Update();

private:
	Deck deck_;
	Dealer dealer_;
	std::vector<Player> players_;

	GameState currentState_;
};

