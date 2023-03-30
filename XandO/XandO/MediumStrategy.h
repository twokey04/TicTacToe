#pragma once

#include "IDifficultyStrategy.h"

class MediumStrategy : public IDifficultyStrategy
{
public:
	virtual uint16_t GetNextMove(const Board& board) override;
};

