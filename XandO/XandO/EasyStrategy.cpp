#include "EasyStrategy.h"

uint16_t EasyStrategy::GetNextMove(const Board& board, const Sign::sign computerSign)
{
	std::vector<uint16_t> availablePositions = board.GetEmptyCells();
	if (availablePositions.size() != 0) {
		return availablePositions[rand() % availablePositions.size()];
	}
	return INT16_MAX;
}
