#pragma once

#include "IGameListener.h"

#include <memory>
#include "IGame.h"
#include <QVector>
#include <QPushButton>
#include <QMessageBox>


class GuiListener: public IGameListener
{
public:
	GuiListener(IGamePtr game, std::array<QPushButton*, 9>& vector);

	void Update();
	void ShowGameState();
private:

	IGamePtr m_game;
	std::array<QPushButton*, 9> m_vector;
};
