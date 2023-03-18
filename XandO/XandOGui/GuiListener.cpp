#include "GuiListener.h"


GuiListener::GuiListener(IGamePtr game, std::array<QPushButton*, 9>& vector)
	: m_game(game)
	, m_vector(vector)
{
}

void GuiListener::Update()
{

	auto board = m_game->GetGameBoard().GetBoard();

	for (size_t index = 0; index < 9; index++) {
		//m_vector[index]->setText(board[index] == Sign::sign::X ? "X" : "O");
		if (board[index] == Sign::sign::X)
			m_vector[index]->setText("X");
		else if (board[index] == Sign::sign::O)
			m_vector[index]->setText("O");
		else m_vector[index]->setText("");
		
	}

}

void GuiListener::ShowGameState()
{
}
