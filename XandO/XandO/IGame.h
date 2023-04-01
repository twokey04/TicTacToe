/**
 *
 * @file IGame.h
 * @brief An abstract interface for a game class that manages gameplay and player moves.
 */
#pragma once

#include <memory>

#include "IGameListener.h"
#include "IPlayer.h"
#include "Board.h"
#include "Difficulty.h"

/**
 *
 * @brief A shared pointer to an IGame object.
 */
using IGamePtr = std::shared_ptr<class IGame>;
/**
 *
 * @brief An abstract interface for a game class that manages gameplay and player moves.
 */
class IGame
{
public:
	/**
	 * @brief Adds a game listener to the game object.
	 * @param ptr A shared pointer to the game listener object.
	 */
	virtual void AddListeners(IGameListenerPtr ptr) = 0;

	/**
	 * @brief Removes a game listener from the game object.
	 * @param ptr A shared pointer to the game listener object.
	 */
	virtual void RemoveListeners(IGameListenerPtr ptr) = 0;

	/**
	 * @brief Notifies all registered game listeners of a game event.
	 */
	virtual void NotifyAll() = 0;

	/**
	 * @brief Produces a game object with the specified difficulty level.
	 * @param difficulty An integer representing the desired difficulty level of the game.
	 * @return A shared pointer to the produced game object.
	 */
	static IGamePtr Produce(int difficulty);

	/**
	 * @brief Runs a round of the game.
	 * @param position An integer representing the position on the game board where the player wants to place their sign.
	 */
	virtual void RunRound(uint16_t position) = 0;

	/**
	 * @brief Places the specified player's sign on the game board at the specified position.
	 * @param position An integer representing the position on the game board where the player wants to place their sign.
	 * @param player A shared pointer to the player object that is placing the sign.
	 * @return A boolean value indicating whether or not the sign was successfully placed on the game board.
	 */
	virtual bool PlaceSign(uint16_t position, IPlayerPtr player) = 0;

	/**
	 * @brief Initializes the player objects and their order of playing.
	 */
	virtual void InitializeGame() = 0;

	/**
	 * @brief Gets the current state of the game board.
	 * @return A Board object representing the current state of the game board.
	 */
	virtual Board GetGameBoard() = 0;

	/**
	 * @brief Gets a shared pointer to the human player object.
	 * @return A shared pointer to the human player object.
	 */
	virtual IPlayerPtr GetPlayer() = 0;

	/**
	 * @brief Gets a shared pointer to the computer player object.
	 * @return A shared pointer to the computer player object.
	 */
	virtual IPlayerPtr GetComputer() = 0;

	/**
	 * @brief A virtual destructor for the IGame class.
	 */
	virtual ~IGame() = default;
};