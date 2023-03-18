#pragma once
#include <memory>

using IGameListenerPtr = std::shared_ptr<class IGameListener>;

class IGameListener
{
public:
	virtual void Update() = 0;
	virtual void ShowGameState() = 0;

	virtual ~IGameListener() = default;
};
