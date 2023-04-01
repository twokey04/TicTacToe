#pragma once

#include "IDifficultyStrategy.h"

class EasyStrategy : public IDifficultyStrategy
{
public:
	virtual uint16_t GetNextMove(Board& board, const Sign::sign computerSign) override;
	virtual Difficulty::Level GetDifficulty() const override;
};

