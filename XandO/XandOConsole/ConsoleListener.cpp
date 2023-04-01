#include "ConsoleListener.h"

ConsoleListener::ConsoleListener(IGamePtr game)
	: m_game(game)
{
}

void ConsoleListener::Update()
{
	
	auto board = m_game->GetGameBoard().GetBoard();

	for (auto index = 0; index < board.size(); ++index)
	{
		if (index % 3 == 0)
			std::cout << "\n";
		if (board[index] == Sign::sign::X)
			std::cout << "X ";
		else if (board[index] == Sign::sign::O)
			std::cout << "O ";
		else std::cout << "_ ";
	}
	std::cout << "\n";


}

void ConsoleListener::ShowGameState() {

	if (m_game->GetGameBoard().CheckGameState() == GameState::gameState::WonO)
		std::cout << "\nO won!\n";
	else if (m_game->GetGameBoard().CheckGameState() == GameState::gameState::WonX)
		std::cout << "\nX won!\n";
	else if (m_game->GetGameBoard().CheckGameState() == GameState::gameState::Tie) std::cout << "\nTie!\n";

}