#include "Player.h"

bool Player::PlaceSign(const uint16_t& position, IBoardPtr board)
{

	if (board->operator[](position) == Sign::sign::None)
	{
		board->operator[](position) = m_sign;
		return true;
	}
	else
		return false;
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

