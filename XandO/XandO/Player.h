#pragma once
#include <iostream>
#include <string>

#include "Sign.h"
#include "Board.h"
#include "IPlayer.h"

class Player: public IPlayer
{
public:
	Player() = default;
	bool PlaceSign(const uint16_t& position, IBoardPtr board);
	std::string GetPlayerName() const;
	void SetPlayerName(const std::string& name);
	void SetSign(const Sign::sign& sign);
private:
	Sign::sign m_sign;
	std::string m_playerName;
};

