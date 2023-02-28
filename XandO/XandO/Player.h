#pragma once
#include <iostream>
#include <string>

#include "Sign.h"
#include "Board.h"

class Player
{
private:
	Sign::sign m_sign;
	std::string m_playerName;
public:
	Player() = default;
	bool PlaceSign(const uint8_t& position, const Board& board);
	std::string GetPlayerName() const;
	void SetPlayerName(const std::string& name);
	void SetSign(const Sign::sign& sign);
};

