#include "Player.h"


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

Sign::sign Player::GetSign() const
{
	return m_sign;
}

