#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QLayout>

#include "ui_XandODifficultyWindow.h"
#include "XandOGui.h"
#include "IGame.h"

class XandODifficultyWindow : public QMainWindow
{
	Q_OBJECT

public:
	XandODifficultyWindow(QWidget *parent = nullptr);
	~XandODifficultyWindow();

private:
	Ui::XandODifficultyWindowClass* ui;
	QComboBox* cbDifficulty;
	QLabel* lblMessage;
	IGamePtr m_game;

private slots:
	void handleComboBoxItemClicked();
};
