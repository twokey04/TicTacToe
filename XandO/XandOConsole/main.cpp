#include <memory>

#include "IGame.h"
#include "ConsoleListener.h"

int main() 
{
	srand(time(NULL));

	int difficulty;
	std::cout << "Choose difficulty (0 - easy, 1 - medium, 2 - hard): ";
	std::cin >> difficulty;

	IGamePtr game = IGame::Produce(difficulty);
	IGameListenerPtr consoleListener = std::make_shared<ConsoleListener>(game);
	game->AddListeners(consoleListener);
	game->InitializeGame();

	uint16_t position;
	while (game->GetGameBoard().CheckGameState() == GameState::gameState::Undetermined) {
		std::cout << "Position: ";
		std::cin >> position;
		game->RunRound(position);
		
	}

	return 0;
}


