#pragma once
#include <array>
#include <vector>
#include <iostream>

#include "Sign.h"

class Board
{

public:
	Board();
	void SetSign(const uint8_t& position, const Sign::sign& sign);
	uint8_t CheckGameState();
	void ClearBoard();
	std::vector<uint8_t> GetEmptyCells() const;

private:
	bool CheckWin(Sign::sign sign);
	Sign::sign GetSign(const uint8_t& position) const;

private:
	std::array<Sign::sign, 9> m_board;
};

