#pragma once
#include <iostream>
#include <string>

class Player
{
public:
	enum Sign {
		X,
		O
	};
private:
	Sign m_sign;
	std::string m_playerName;
public:
	Player() = default;
	bool PlaceSign(const uint8_t& position, const Board& board);
	std::string GetPlayerName() const;
	void SetPlayerName(const std::string& name);
	void SetSign(const Sign& sign);
};

