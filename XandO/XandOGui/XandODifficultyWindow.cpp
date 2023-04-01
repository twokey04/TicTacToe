#include "XandODifficultyWindow.h"

XandODifficultyWindow::XandODifficultyWindow(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::XandODifficultyWindowClass())
{
	ui->setupUi(this);

	this->setFixedSize(330, 330);

	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	lblMessage = new QLabel(this);
	lblMessage->setText("Pick a difficulty to play!");
	lblMessage->setAlignment(Qt::AlignCenter);

	cbDifficulty = new QComboBox(this);
	cbDifficulty->addItem("Easy");
	cbDifficulty->addItem("Medium");
	cbDifficulty->addItem("Hard");

	QHBoxLayout* layout = new QHBoxLayout(centralWidget);
	layout->addWidget(lblMessage, 0, Qt::AlignCenter);
	layout->addWidget(cbDifficulty, 0, Qt::AlignCenter);

	connect(cbDifficulty, QOverload<int>::of(&QComboBox::activated), this, &XandODifficultyWindow::handleComboBoxItemClicked);

}

void XandODifficultyWindow::handleComboBoxItemClicked() {
	if (cbDifficulty->currentText() == "Easy")
	{
		m_game = IGame::Produce(0);
		m_game->GetPlayer()->SetPlayerName("Player");
		XandOGui* window = new XandOGui(m_game, this);
		this->close();
		window->show();
	}
	else if (cbDifficulty->currentText() == "Medium")
	{
		m_game = IGame::Produce(1);
		m_game->GetPlayer()->SetPlayerName("Player");
		XandOGui* window = new XandOGui(m_game, this);
		this->close();
		window->show();
	}else if (cbDifficulty->currentText() == "Hard")
	{
		m_game = IGame::Produce(2);
		m_game->GetPlayer()->SetPlayerName("Player");
		XandOGui* window = new XandOGui(m_game, this);
		this->close();
		window->show();
	}
}

XandODifficultyWindow::~XandODifficultyWindow()
{
	delete ui;
}
