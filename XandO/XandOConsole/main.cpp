#include <memory>

#include "Game.h"

int main() 
{
	IGamePtr game = IGame::Produce();
	game->RunConsole();

	return 0;
}


