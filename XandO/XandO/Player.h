#pragma once
#include <iostream>
#include <string>

class Player
{
	std::string playerName;
public:
	Player() = default;
	bool PlacePosition(const uint8_t& position);
	std::string GetPlayerName();
	void SetPlayerName(const std::string& name);
	void PrintPlayer();
};

