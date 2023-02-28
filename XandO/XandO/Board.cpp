#include "Board.h"

Board::Board()
{
	m_board = {
		Sign::sign::None, Sign::sign::None, Sign::sign::None,
		Sign::sign::None, Sign::sign::None, Sign::sign::None,
		Sign::sign::None, Sign::sign::None, Sign::sign::None
	};
}

void Board::SetSign(const uint8_t& position, const Sign::sign& sign)
{
	if (GetSign(position) == Sign::sign::None)
		m_board[position] = sign;
	else
		return;
}

uint8_t Board::CheckGameState()
{
	if (CheckWin(Sign::sign::O))
		return 0;
	else if (CheckWin(Sign::sign::X))
		return 1;
	else
		return 2;
}

void Board::ClearBoard()
{
	m_board.fill(Sign::sign::None);
}

std::vector<uint8_t> Board::GetEmptyCells() const
{
	std::vector<uint8_t> emptyCells;
	for (uint8_t position = 0; position < m_board.size(); ++position) {
		if (m_board.at(position) == Sign::sign::None)
			emptyCells.emplace_back(position);
	}
	return emptyCells;
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

Sign::sign Board::GetSign(const uint8_t& position) const
{
	return m_board[position];
}
