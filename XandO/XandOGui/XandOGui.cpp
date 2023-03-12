#include "XandOGui.h"


XandOGui::XandOGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::XandOGuiClass())
{
    ui->setupUi(this);

	this->setFixedSize(330, 330);
    
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout* gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(0);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            QPushButton* button = new QPushButton(QString(""), centralWidget);
            button->setFixedSize(100, 100);
			connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked));
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
}

void XandOGui::RunGui()
{
	srand(time(NULL));
	m_player->SetSign(Sign::sign::X);
	m_computer->SetSign(Sign::sign::O);
	m_order.push(m_player);
	m_order.push(m_computer);
	while (1)
	{
		IPlayerPtr tmpPlayer = m_order.front();
		uint16_t pickedPosition;
		if (tmpPlayer->GetPlayerName() == "")
		{
			std::vector<uint16_t> availablePositions = m_board->GetEmptyCells();
			if (availablePositions.size() != 0)
			{
				pickedPosition = rand() % availablePositions.size();
				tmpPlayer->PlaceSign(availablePositions[pickedPosition], m_board);
				boardButtons[availablePositions[pickedPosition]]->setText(tmpPlayer->GetSign() == Sign::sign::X ? "X" : "O");
			}
			else break;
		}
		else
		{

		}
		if (m_board->CheckGameState() != GameState::gameState::Undetermined)
			break;
		m_order.pop();
		m_order.push(tmpPlayer);
	}
	/*if (m_board->CheckGameState() == GameState::gameState::WonO)
		std::cout << "O won!\n";
	else if (m_board->CheckGameState() == GameState::gameState::WonX)
		std::cout << "X won!\n";
	else std::cout << "Tie!\n";*/
}

void XandOGui::onButtonClicked()
{
	QPushButton* button = qobject_cast<QPushButton*>(sender());

	if (button->text().isEmpty())
		button->setText("X");
}

XandOGui::~XandOGui()
{
    delete ui;
}
