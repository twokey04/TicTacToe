#pragma once
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Sign.h"
#include "IBoard.h"

class Board : public IBoard
{

public:
	Board();
	void SetSign(const uint16_t& position, const Sign::sign& sign) override;
	uint16_t CheckGameState() override;
	void ClearBoard() override;
	std::vector<uint16_t> GetEmptyCells() const override;
	Sign::sign& operator[](const uint16_t& position) override;
	void PrintBoard() override;

private:
	bool CheckTie();
	bool CheckWin(Sign::sign sign);
	Sign::sign GetSign(const uint16_t& position) const;

private:
	std::array<Sign::sign, 9> m_board;
};

