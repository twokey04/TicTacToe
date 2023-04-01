#pragma once

#include <cstdlib>

#include "Board.h"

class IDifficultyStrategy {
public:
	virtual uint16_t GetNextMove(Board& board, const Sign::sign computerSign) = 0;
};