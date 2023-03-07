#pragma once

#include <memory>
#include <string>

#include "Sign.h"
#include "IBoard.h"

using IPlayerPtr = std::shared_ptr<class IPlayer>;

class IPlayer
{
public:
	static IPlayerPtr Produce();
	virtual bool PlaceSign(const uint16_t& position, IBoardPtr board) = 0;
	virtual std::string GetPlayerName() const = 0;
	virtual void SetPlayerName(const std::string& name) = 0;
	virtual void SetSign(const Sign::sign& sign) = 0;
};

