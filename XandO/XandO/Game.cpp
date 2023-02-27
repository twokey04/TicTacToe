#include "Game.h"
#include <vector>

Game::Game()
{
	std::cout << "Enter your name!\n";
	std::string tmpName;
	std::cin >> tmpName;
	m_player.SetPlayerName(tmpName);
}

void Game::Run()
{
	srand(time(NULL));
	uint8_t random = rand() % 2;
	switch (random)
	{
	case 0: 
		//0 - incepe computer
		m_computer.SetSign(Player::Sign::X);
		m_player.SetSign(Player::Sign::O);
		m_order.push(m_computer);
		m_order.push(m_player);
		break;
	case 1: 
		//1 - incepe player
		m_player.SetSign(Player::Sign::O);
		m_computer.SetSign(Player::Sign::X);
		m_order.push(m_player);
		m_order.push(m_computer);
		break;
	}
	while (1)
	{
		Player tmpPlayer = m_order.front();
		int pickedPosition;
		if (tmpPlayer.GetPlayerName() == "")
		{
			std::vector<uint8_t> availablePositions = m_board.GetEmptyCells();
			pickedPosition = rand() % availablePositions.size();
			tmpPlayer.PlaceSign(pickedPosition, m_board);
		}
		else
		{
			std::cin >> pickedPosition;
			tmpPlayer.PlaceSign(pickedPosition, m_board);
		}
		m_order.pop();
	   
	}
}
