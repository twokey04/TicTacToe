#include "Game.h"
#include <vector>



Game::Game(Difficulty::Level level)
{
	m_player = IPlayer::Produce();
	m_computer = IPlayer::Produce();
	std::cout << "Enter your name!\n";
	std::string tmpName;
	std::cin >> tmpName;
	m_player->SetPlayerName(tmpName);
	
	switch (level) {
	case Difficulty::Level::Easy:
		m_strategy = std::make_shared<EasyStrategy>();
		break;
	case Difficulty::Level::Medium:
		m_strategy = std::make_shared<MediumStrategy>();
		break;
	case Difficulty::Level::Hard:
		m_strategy = std::make_shared<HardStrategy>();
		break;
	}
}

void Game::InitializeGame() 
{
	uint16_t random = rand() % 2;
	switch (random)
	{
	case 0:
		//0 - incepe computer
		m_computer->SetSign(Sign::sign::X);
		m_player->SetSign(Sign::sign::O);
		m_order.push(m_computer);
		m_order.push(m_player);
		RunRound(-1);
		break;
	case 1:
		//1 - incepe player
		m_player->SetSign(Sign::sign::X);
		m_computer->SetSign(Sign::sign::O);
		m_order.push(m_player);
		m_order.push(m_computer);
		NotifyAll();
		break;
	}
}

Board Game::GetGameBoard()
{
	return m_board;
}

IPlayerPtr Game::GetPlayer()
{
	return m_player;
}

void Game::AddListeners(IGameListenerPtr ptr)
{
	m_listeners.push_back(ptr);
}

void Game::RemoveListeners(IGameListenerPtr ptr)
{
	m_listeners.erase(std::find(m_listeners.begin(), m_listeners.end(), ptr));
}

void Game::NotifyAll()
{
	for (auto obs : m_listeners)
	{
		obs->Update();
		obs->ShowGameState();
	}
}

void Game::RunRound(uint16_t position)
{
		IPlayerPtr tmpPlayer = m_order.front();
		
		uint16_t pickedPosition;

		if (tmpPlayer == m_player) 
		{
			if (!PlaceSign(position, tmpPlayer)) 
			{
				return;
			}
			else 
			{
				m_order.pop();
				m_order.push(tmpPlayer);
				tmpPlayer = m_order.front();
			}
		}
		
		if (tmpPlayer == m_computer && m_board.CheckGameState() == GameState::gameState::Undetermined)
		{
			uint16_t nextMove = m_strategy->GetNextMove(m_board, tmpPlayer->GetSign());
			PlaceSign(nextMove, tmpPlayer);
		}
		
		m_order.pop();
		m_order.push(tmpPlayer);
			
		for (auto obs : m_listeners)
			NotifyAll();
}

bool Game::PlaceSign(uint16_t position, IPlayerPtr player)
{
	if (position < 0 || position > 8)
		return false;
	if (m_board.operator[](position) == Sign::sign::None)
	{
		m_board.operator[](position) = player->GetSign();
		return true;
	}
	else
		return false;
	
}

IPlayerPtr Game::GetComputer() {
	return m_computer;
}
