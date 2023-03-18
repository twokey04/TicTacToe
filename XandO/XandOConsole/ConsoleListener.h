#pragma once

//#include "IGameListener.h"

#include <memory>
#include "IGame.h"
#include <iostream>

class ConsoleListener : public IGameListener
{
public:

	ConsoleListener(IGamePtr game);

	void Update();
	void ShowGameState();

private:

	IGamePtr m_game;
};
