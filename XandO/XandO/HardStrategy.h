#pragma once

#include "IDifficultyStrategy.h"

class HardStrategy : public IDifficultyStrategy
{
public:
	/**
	 * @brief Virtual method to get the next move based on the current state of the board.
	 * This method uses the Minimax alpha-beta pruning algorithm to find the best possible
	 * position to place the sign.
	 * @param board The current state of the game board.
	 * @param computerSign The sign used by the computer player.
	 * @return The index of the board square where the computer player should place their next move.
	 */
	virtual uint16_t GetNextMove(Board& board, const Sign::sign computerSign) override;

	/**
	 * @brief Implementation of the minimax algorithm used by the HardStrategy difficulty strategy.
	 * This function recursively applies the minimax algorithm to determine the best move for the computer player.
	 * It assigns a score to each possible move based on the resulting state of the board, and returns the maximum
	 * or minimum score depending on whether it is maximizing or minimizing the score for the computer player.
	 * @param board The current state of the game board.
	 * @param depth The current depth of the search tree.
	 * @param alpha The alpha value for alpha-beta pruning.
	 * @param beta The beta value for alpha-beta pruning.
	 * @param maximizingPlayer Whether the function is maximizing the score for the computer player.
	 * @param computerSign The sign used by the computer player.
	 * @return The score assigned to the best possible move for the computer player.
	 */
	int Minimax(Board& board, int depth, int alpha, int beta, bool maximizingPlayer, const Sign::sign& computerSign);
	virtual Difficulty::Level GetDifficulty() const override;
};

