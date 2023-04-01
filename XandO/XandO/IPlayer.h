/**
 *
 * @file IPlayer.h
 * @brief Contains the interface for a Tic Tac Toe player.
 */
#pragma once

#include <memory>
#include <string>

#include "Sign.h"

/**
 *
 * @brief A shared pointer alias for the IPlayer class.
 */
using IPlayerPtr = std::shared_ptr<class IPlayer>;

/**
 *
 * @brief The interface for a Tic Tac Toe player.
 */
class IPlayer
{
public:
	/**
	 *
	 * @brief Creates a new IPlayer instance.
	 * @return A shared pointer to the new IPlayer instance.
	 */
	static IPlayerPtr Produce();

	/**
	 *
	 * @brief Returns the name of the player.
	 * @return The name of the player.
	 */
	virtual std::string GetPlayerName() const = 0;

	/**
	 *
	 * @brief Sets the name of the player.
	 * @param name The name of the player.
	 */
	virtual void SetPlayerName(const std::string& name) = 0;

	/**
	 *
	 * @brief Sets the sign used by the player.
	 * @param sign The sign used by the player.
	 */
	virtual void SetSign(const Sign::sign& sign) = 0;

	/**
	 * 
	 * @brief Returns the sign used by the player.
	 * @return The sign used by the player.
	 */
	virtual Sign::sign GetSign() const = 0;

	/**
	 * 
	 * @brief Destroys the IPlayer instance.
	 */
	virtual ~IPlayer() = default;
};