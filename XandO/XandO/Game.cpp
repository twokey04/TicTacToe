#include "Game.h"
#include <vector>

Game::Game()
{
	std::cout << "Enter your name!\n";
	std::string tmpName;
	std::cin >> tmpName;
	m_player.SetPlayerName(tmpName);
}

void Game::RunConsole()
{
	srand(time(NULL));
	uint16_t random = rand() % 2;
	switch (random)
	{
	case 0: 
		//0 - incepe computer
		m_computer.SetSign(Sign::sign::X);
		m_player.SetSign(Sign::sign::O);
		m_order.push(m_computer);
		m_order.push(m_player);
		break;
	case 1: 
		//1 - incepe player
		m_player.SetSign(Sign::sign::X);
		m_computer.SetSign(Sign::sign::O);
		m_order.push(m_player);
		m_order.push(m_computer);
		m_board.PrintBoard();
		break;
	}
	while (1)
	{
		Player tmpPlayer = m_order.front();
		uint16_t pickedPosition;
		if (tmpPlayer.GetPlayerName() == "")
		{
			std::vector<uint16_t> availablePositions = m_board.GetEmptyCells();
			if (availablePositions.size() != 0)
			{
				pickedPosition = rand() % availablePositions.size();
				tmpPlayer.PlaceSign(availablePositions[pickedPosition], m_board);
			}
			else break;

			m_board.PrintBoard();
			std::cout << "\nComputer placed at position " << availablePositions[pickedPosition] << '\n';
		}
		else
		{
			do 
			{
				std::cout << "\nPick position: ";
				std::cin >> pickedPosition;
			} while (tmpPlayer.PlaceSign(pickedPosition, m_board) == false);
			m_board.PrintBoard();
			
		}
		if (m_board.CheckGameState() != 3)
			break;
		m_order.pop();
		m_order.push(tmpPlayer);
	}
	if (m_board.CheckGameState() == 0)
		std::cout << "O won!\n";
	else if (m_board.CheckGameState() == 1)
		std::cout << "X won!\n";
	else std::cout << "Tie!\n";
}
