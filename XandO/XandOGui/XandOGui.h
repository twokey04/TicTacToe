#pragma once

#include <QtWidgets/QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

#include <array>
#include <queue>
#include <algorithm>

#include "ui_XandOGui.h"
#include "qpushbutton.h"
#include "qvector.h"
#include "qgridlayout.h"
#include <qmessagebox.h>

#include "IBoard.h"
#include "IPlayer.h"
#include "Sign.h"

QT_BEGIN_NAMESPACE
namespace Ui { class XandOGuiClass; };
QT_END_NAMESPACE

class XandOGui : public QMainWindow
{
    Q_OBJECT

public:
    XandOGui(QWidget *parent = nullptr);
    void RunGui();
    ~XandOGui();

private:
    Ui::XandOGuiClass *ui;
    std::array<QPushButton*, 9> boardButtons;
    QGridLayout* gridLayout;
    IBoardPtr m_board;
    IPlayerPtr m_player;
    IPlayerPtr m_computer;
    std::queue<IPlayerPtr> m_order;

private slots:
    void onButtonClicked();
};
