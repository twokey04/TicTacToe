#include "GuiListener.h"


GuiListener::GuiListener(IGamePtr game, std::array<QPushButton*, 9>& vector)
	: m_game(game)
	, m_vector(vector)
{
}

void GuiListener::Update()
{

	auto board = m_game->GetGameBoard().GetBoard();

	for (auto index = 0; index < board.size(); ++index)
	{
		if (board[index] == Sign::sign::X)
			m_vector[index]->setText("X");
		else if (board[index] == Sign::sign::O)
			m_vector[index]->setText("O");
		else m_vector[index]->setText("");
	}

}

void GuiListener::ShowGameState()
{
	auto state = m_game->GetGameBoard().CheckGameState();
	if (state != GameState::gameState::Undetermined) {
		if (state == GameState::gameState::WonO)
			QMessageBox::information(nullptr, "Game Over", "O won!");
		else if (state == GameState::gameState::WonX)
			QMessageBox::information(nullptr, "Game Over", "X won!");
		else
			QMessageBox::information(nullptr, "Game Over", "Tie!");
		return;
	}
}
