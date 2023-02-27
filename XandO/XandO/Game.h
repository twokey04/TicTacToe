#pragma once
#include "Player.h"
#include "Board.h"
#include <cstdlib>
#include <iostream>
#include <queue>

class Game
{
	Board m_board;
	Player m_player;
	Player m_computer;
	std::queue<Player> m_order;
public:
	Game();
	void Run();
};

