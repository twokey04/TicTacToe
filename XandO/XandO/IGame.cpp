#include "IGame.h"
#include "Game.h"

IGamePtr IGame::Produce()
{
	return std::make_shared<Game>();
}
