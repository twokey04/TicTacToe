#pragma once
#include <cstdlib>
#include <iostream>
#include <queue>

#include "IGame.h"
#include "EasyStrategy.h"
#include "MediumStrategy.h"
#include "HardStrategy.h"

class Game: public IGame
{
	Board m_board;
	IPlayerPtr m_player;
	IPlayerPtr m_computer;
	std::queue<IPlayerPtr> m_order;
	std::vector<IGameListenerPtr> m_listeners;
	std::shared_ptr<IDifficultyStrategy> m_strategy;

public:
	Game(Difficulty::Level level);
	void InitializeGame() override;
	Board GetGameBoard() override;
	IPlayerPtr GetPlayer() override;
	IPlayerPtr GetComputer() override;
	void AddListeners(IGameListenerPtr ptr) override;
	void RemoveListeners(IGameListenerPtr ptr) override;
	void NotifyAll() override;
	void RunRound(uint16_t position) override;
	bool PlaceSign(uint16_t position, IPlayerPtr player);
};

