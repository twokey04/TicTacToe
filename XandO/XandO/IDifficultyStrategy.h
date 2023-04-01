#pragma once

#include <cstdlib>

#include "Board.h"
#include "Difficulty.h"

class IDifficultyStrategy {
public:
	virtual uint16_t GetNextMove(Board& board, const Sign::sign computerSign) = 0;
	virtual Difficulty::Level GetDifficulty() const = 0;
};