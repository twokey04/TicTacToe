#pragma once
#include <cstdlib>
#include <iostream>
#include <queue>

#include "Sign.h"
#include "Player.h"
#include "Board.h"
#include "IGame.h"

class Game: public IGame
{
	Board m_board;
	Player m_player;
	Player m_computer;
	std::queue<Player> m_order;
public:
	Game();
	void RunConsole() override;
};

