#pragma once

#include "IDifficultyStrategy.h"

class HardStrategy : public IDifficultyStrategy
{
public:
	virtual uint16_t GetNextMove(const Board& board, const Sign::sign computerSign) override;
};

