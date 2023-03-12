#include "XandOGui.h"


XandOGui::XandOGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::XandOGuiClass())
{
    ui->setupUi(this);

	this->setFixedSize(330, 330);
    
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(0);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton* button = new QPushButton(QString(""), centralWidget);
            button->setFixedSize(100, 100);
			connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
            gridLayout->addWidget(button, row, col);
        }
    }
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QLayoutItem* item = gridLayout->itemAtPosition(row / 3, col % 3);
            if (item) {
                QPushButton* button = qobject_cast<QPushButton*>(item->widget());
                if (button) {
                    boardButtons[row * 3 + col] = button;
                }
            }
        }
    }
    m_board = IBoard::Produce();
    m_player = IPlayer::Produce();
    m_computer = IPlayer::Produce();
    m_player->SetPlayerName("Player");

    srand(time(NULL));
    m_player->SetSign(Sign::sign::X);
    m_computer->SetSign(Sign::sign::O);
    m_order.push(m_player);
    m_order.push(m_computer);
}

void XandOGui::onButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) {
        return;
    }

    if (button->text().isEmpty()) {
        int index = gridLayout->indexOf(button);
        if (index >= 0 && index < 9) {
            m_board->SetSign(index, m_player->GetSign());
            button->setText(QString::fromStdString(m_player->GetSign() == Sign::sign::X ? "X" : "O"));
        }
        else {
            qDebug() << "Invalid row or column index: ";
        }
    }

    GameState::gameState state = m_board->CheckGameState();
    if (state != GameState::gameState::Undetermined) {
        if (state == GameState::gameState::WonO)
            QMessageBox::information(this, "Game Over", "O won!");
        else if (state == GameState::gameState::WonX)
            QMessageBox::information(this, "Game Over", "X won!");
        else
            QMessageBox::information(this, "Game Over", "Tie!");
        return;
    }

    IPlayerPtr tmp = m_order.front();
    m_order.pop();
    m_order.push(tmp);

    IPlayerPtr tmpPlayer = m_order.front();
    if (tmpPlayer->GetPlayerName() == "")
    {
        std::vector<uint16_t> availablePositions = m_board->GetEmptyCells();
        if (availablePositions.size() != 0)
        {
            uint16_t pickedPosition = rand() % availablePositions.size();
            tmpPlayer->PlaceSign(availablePositions[pickedPosition], m_board);
            boardButtons[availablePositions[pickedPosition]]->setText(QString::fromStdString(tmpPlayer->GetSign() == Sign::sign::X ? "X" : "O"));
        }
        else {
            QMessageBox::information(this, "Game Over", "Tie!");
            return;
        }
    }

    state = m_board->CheckGameState();
    if (state != GameState::gameState::Undetermined) {
        if (state == GameState::gameState::WonO)
            QMessageBox::information(this, "Game Over", "O won!");
        else if (state == GameState::gameState::WonX)
            QMessageBox::information(this, "Game Over", "X won!");
        else
            QMessageBox::information(this, "Game Over", "Tie!");
        return;
    }

    tmp = m_order.front();
    m_order.pop();
    m_order.push(tmp);
}

XandOGui::~XandOGui()
{
    delete ui;
}
