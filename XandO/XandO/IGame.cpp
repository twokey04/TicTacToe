#include "IGame.h"
#include "Game.h"

IGamePtr IGame::Produce(int difficulty)
{
	switch (difficulty) {
	case 0:
		return std::make_shared<Game>(Difficulty::Level::Easy);
	case 1:
		return std::make_shared<Game>(Difficulty::Level::Medium);
	case 2:
		return std::make_shared<Game>(Difficulty::Level::Hard);
	default:
		return std::make_shared<Game>(Difficulty::Level::Easy);
	}
}
