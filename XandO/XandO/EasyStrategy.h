#pragma once

#include "IDifficultyStrategy.h"

class EasyStrategy : public IDifficultyStrategy
{
public:
	/**
	 * @brief Virtual method to get the next move based on the current state of the board.
	 * This method choses a random empty position from the board.
	 * @param board The current state of the game board.
	 * @param computerSign The sign used by the computer player.
	 * @return The index of the board square where the computer player should place their next move.
	 */
	virtual uint16_t GetNextMove(Board& board, const Sign::sign computerSign) override;
	virtual Difficulty::Level GetDifficulty() const override;
};

