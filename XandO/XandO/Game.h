#pragma once
#include <cstdlib>
#include <iostream>
#include <queue>

//#include "IBoard.h"
#include "IGame.h"

class Game: public IGame
{
	Board m_board;
	IPlayerPtr m_player;
	IPlayerPtr m_computer;
	std::queue<IPlayerPtr> m_order;
	std::vector<IGameListenerPtr> m_listeners;
public:
	Game();
	void InitializeGame() override;
	Board GetGameBoard() override;
	IPlayerPtr GetPlayer() override;
	IPlayerPtr GetComputer() override;
	void AddListeners(IGameListenerPtr ptr) override;
	void RemoveListeners(IGameListenerPtr ptr) override;
	void NotifyAll() override;
	void RunConsole(uint16_t position) override;
	bool PlaceSign(uint16_t position, IPlayerPtr player);
};

