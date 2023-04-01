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
	/**
	 * @brief Virtual method to get the next move based on the current state of the board.
	 * This method initialises the queue of order and uses the first strategy from the queue, 
	 * then adds it to the back of the queue. This function uses at a time EasyStrategy and
	 * HardStrategy.
	 * @param board The current state of the game board.
	 * @param computerSign The sign used by the computer player.
	 * @return The index of the board square where the computer player should place their next move.
	 */
	virtual uint16_t GetNextMove( Board& board, const Sign::sign computerSign) override;
	virtual Difficulty::Level GetDifficulty() const override;
};

