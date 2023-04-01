#include "XandOGui.h"


XandOGui::XandOGui(IGamePtr game, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::XandOGuiClass())
    , m_game(game)
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
            boardButtons[row * 3 + col] = button;
        }
    }

    m_listener = std::make_shared<GuiListener>(m_game, boardButtons);
    m_game->AddListeners(m_listener);
    m_game->InitializeGame();

    m_game->GetPlayer()->SetPlayerName("Player");

    srand(time(NULL));
}


void XandOGui::onButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) {
        return;
    }

    if (button->text().isEmpty()) {
        int index = gridLayout->indexOf(button);
        m_game->RunRound(index);
    }
}

XandOGui::~XandOGui()
{
    delete ui;
}
