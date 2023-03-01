#include "Game.h"
#include <memory>

int main() {
	//IGamePtr game = std::make_shared<Game>();
	IGamePtr game = IGame::Produce();
	game -> RunConsole();
	return 0;
}