#pragma once

#include "IDifficultyStrategy.h"

class HardStrategy : public IDifficultyStrategy
{
public:
	virtual uint16_t GetNextMove(Board& board, const Sign::sign computerSign) override;
	int Minimax(Board& board, int depth, int alpha, int beta, bool maximizingPlayer, const Sign::sign& computerSign);
};

