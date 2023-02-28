#include "Player.h"

bool Player::PlaceSign(const uint8_t& position,const Board& board)
{
	board[position] = m_sign;
}

std::string Player::GetPlayerName() const
{
	return m_playerName;
}

void Player::SetPlayerName(const std::string& name)
{
	m_playerName = name;
}

void Player::SetSign(const Sign::sign& sign)
{
	m_sign = sign;
}

