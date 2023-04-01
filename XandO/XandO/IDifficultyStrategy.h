/**
 *
 * @file IDifficultyStrategy.h
 * @brief Header file for the IDifficultyStrategy abstract class
 */
#pragma once

#include <cstdlib>

#include "Board.h"
#include "Difficulty.h"

/**
 *
 * @brief Abstract class representing a difficulty strategy for the Tic Tac Toe game.
 * This class defines an interface for different difficulty strategies that can be implemented to provide
 * different levels of challenge for the game. Subclasses must implement the GetNextMove() method to provide
 * a move based on the current state of the board.
 */
class IDifficultyStrategy {
public:
/**
 * @brief Virtual method to get the next move based on the current state of the board.
 * This method must be implemented by subclasses to return a valid move for the computer player based on
 * the current state of the board and on the strategy used.
 * @param board The current state of the game board.
 * @param computerSign The sign used by the computer player.
 * @return The index of the board square where the computer player should place their next move.
 */
	virtual uint16_t GetNextMove(Board& board, const Sign::sign computerSign) = 0;
	virtual Difficulty::Level GetDifficulty() const = 0;
};