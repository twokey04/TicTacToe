#pragma once

#include "IDifficultyStrategy.h"
#include "EasyStrategy.h"
#include "HardStrategy.h"

#include <queue>

class MediumStrategy : public IDifficultyStrategy
{
private:
    std::unique_ptr<IDifficultyStrategy> easyMove = std::make_unique<EasyStrategy>();
    std::unique_ptr<IDifficultyStrategy> hardMove = std::make_unique<HardStrategy>();
    std::queue<std::unique_ptr<IDifficultyStrategy>> order;
    bool initialized = false;
   
public:
	virtual uint16_t GetNextMove( Board& board, const Sign::sign computerSign) override;
	virtual Difficulty::Level GetDifficulty() const override;
};

