#include "IPlayer.h"
#include "Player.h"

IPlayerPtr IPlayer::Produce()
{
	return std::make_shared<Player>();
}