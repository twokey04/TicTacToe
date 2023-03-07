#pragma once

#include <memory>


using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
public:
    static IGamePtr Produce();
    virtual void RunConsole() = 0;
    virtual ~IGame() = default;
};