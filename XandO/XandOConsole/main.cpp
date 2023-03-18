#include <memory>

#include "IGame.h"
#include "ConsoleListener.h"

int main() 
{
	IGamePtr game = IGame::Produce();
	IGameListenerPtr consoleListener = std::make_shared<ConsoleListener>(game);
	game->AddListeners(consoleListener);
	game->InitializeGame();

	uint16_t position;
	while (game->GetGameBoard().CheckGameState() == GameState::gameState::Undetermined) {
		std::cout << "Position: ";
		std::cin >> position;
		game->RunConsole(position);
		
	}

	return 0;
}


