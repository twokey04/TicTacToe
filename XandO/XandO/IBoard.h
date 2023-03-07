#pragma once

#include <memory>
#include <vector>

#include "Sign.h"

using IBoardPtr = std::shared_ptr<class IBoard>;

class IBoard
{
	static IBoardPtr Produce();
	virtual void SetSign(const uint16_t& position, const Sign::sign& sign) = 0;
	virtual uint16_t CheckGameState() = 0;
	virtual void ClearBoard() = 0;
	virtual std::vector<uint16_t> GetEmptyCells() const = 0;
	virtual Sign::sign& operator[](const uint16_t& position) = 0;
	virtual void PrintBoard() = 0;
};