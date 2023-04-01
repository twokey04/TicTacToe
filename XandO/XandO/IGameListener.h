/**
 *
 * @file IGameListener.h
 * @brief Defines the IGameListener interface for updating game state and displaying the game board.
 */
#pragma once
#include <memory>

/**
 *
 * @brief A shared pointer to an IGameListener object.
 */
using IGameListenerPtr = std::shared_ptr<class IGameListener>;

/**
 *
 * @class IGameListener
 *
 * @brief An interface for classes that listen for updates to the game state and display the game board.
 */
class IGameListener
{
public:
	/**
	 *
	 * @brief Displays the current state of the board.
	 */
	virtual void Update() = 0;
	
	/**
	 *
	 * @brief Displays the current game state.
	 */
	virtual void ShowGameState() = 0;

	/**
	 *
	 * @brief Virtual destructor for the interface.
	 */
	virtual ~IGameListener() = default;
};