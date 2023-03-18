#include "Board.h"

Board::Board()
{
	m_board = {
		Sign::sign::None, Sign::sign::None, Sign::sign::None,
		Sign::sign::None, Sign::sign::None, Sign::sign::None,
		Sign::sign::None, Sign::sign::None, Sign::sign::None
	};
}

std::array<Sign::sign, 9> Board::GetBoard() const 
{
	return m_board;
}

void Board::SetSign(const uint16_t& position, const Sign::sign& sign)
{
	if (GetSign(position) == Sign::sign::None)
		m_board[position] = sign;
	else
		return;
}

GameState::gameState Board::CheckGameState()
{
	if (CheckWin(Sign::sign::O))
		return GameState::gameState::WonO;
	else if (CheckWin(Sign::sign::X))
		return GameState::gameState::WonX;
	else if (CheckTie())
		return GameState::gameState::Tie;
	else return GameState::gameState::Undetermined;
}

void Board::ClearBoard()
{
	m_board.fill(Sign::sign::None);
}

std::vector<uint16_t> Board::GetEmptyCells() const
{
	std::vector<uint16_t> emptyCells;
	for (size_t position = 0; position < m_board.size(); ++position) {
		if (m_board[position] == Sign::sign::None)
			emptyCells.emplace_back(position);
	}
	return emptyCells;
}

bool Board::CheckTie()
{
	return std::find(m_board.begin(),m_board.end(), Sign::sign::None) == m_board.end();
}

bool Board::CheckWin(Sign::sign sign)
{
	if (
		m_board[0] == sign && m_board[1] == sign && m_board[2] == sign ||
		m_board[3] == sign && m_board[4] == sign && m_board[5] == sign ||
		m_board[6] == sign && m_board[7] == sign && m_board[8] == sign ||

		m_board[0] == sign && m_board[3] == sign && m_board[6] == sign ||
		m_board[1] == sign && m_board[4] == sign && m_board[7] == sign ||
		m_board[2] == sign && m_board[5] == sign && m_board[8] == sign ||

		m_board[0] == sign && m_board[4] == sign && m_board[8] == sign ||
		m_board[2] == sign && m_board[4] == sign && m_board[6] == sign
		) return true;
	return false;
}

Sign::sign Board::GetSign(const uint16_t& position) const
{
	return m_board[position];
}

Sign::sign& Board::operator[](const uint16_t& position)
{
	if (position < 0 || position > 8)
		throw "Board index out of bound.";

	return m_board[position];
}

void Board::PrintBoard()
{
	for (auto index = 0; index < m_board.size(); ++index)
	{
		if (index % 3 == 0)
			std::cout << "\n";
		if (m_board[index] == Sign::sign::X)
			std::cout << "X ";
		else if (m_board[index] == Sign::sign::O)
			std::cout << "O ";
		else std::cout << "_ ";
    }
	std::cout << "\n";
}
