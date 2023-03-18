#pragma once

#include <memory>
#include <string>

#include "Sign.h"

using IPlayerPtr = std::shared_ptr<class IPlayer>;

class IPlayer
{
public:
	static IPlayerPtr Produce();
	virtual std::string GetPlayerName() const = 0;
	virtual void SetPlayerName(const std::string& name) = 0;
	virtual void SetSign(const Sign::sign& sign) = 0;
	virtual Sign::sign GetSign() const = 0;

	virtual ~IPlayer() =  default;
};

