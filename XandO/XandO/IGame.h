#pragma once

#include <memory>

#include "IGameListener.h"
#include "IPlayer.h"
#include "Board.h"

using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
public:
    virtual void AddListeners(IGameListenerPtr ptr) = 0;
    virtual void RemoveListeners(IGameListenerPtr ptr) = 0;
    virtual void NotifyAll() = 0;
    static IGamePtr Produce();
    virtual void RunConsole(uint16_t position) = 0;
    
    virtual bool PlaceSign(uint16_t position, IPlayerPtr player) = 0;
    virtual void InitializeGame() = 0;

    virtual Board GetGameBoard() = 0;
    virtual IPlayerPtr GetPlayer() = 0;
    virtual IPlayerPtr GetComputer() = 0;

    virtual ~IGame() = default;
};