#include "EasyStrategy.h"

uint16_t EasyStrategy::GetNextMove(Board& board, const Sign::sign computerSign)
{
	std::vector<uint16_t> availablePositions = board.GetEmptyCells();
	if (availablePositions.size() != 0) {
		return availablePositions[rand() % availablePositions.size()];
	}
	return std::numeric_limits<uint16_t>::max();
}

Difficulty::Level EasyStrategy::GetDifficulty() const
{
	return Difficulty::Level::Easy;
}
