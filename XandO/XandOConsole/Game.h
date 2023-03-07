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
	IBoardPtr m_board;
	IPlayerPtr m_player;
	IPlayerPtr m_computer;
	std::queue<IPlayerPtr> m_order;
public:
	Game();
	void RunConsole() override;
};

