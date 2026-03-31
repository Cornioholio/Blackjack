#include "GameManager.h"

int main() 
{
	std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
	while (true)
	{
		gameManager->Update();
	}
	return 0;
}