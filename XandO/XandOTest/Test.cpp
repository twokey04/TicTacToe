#include "includes.h"


class MockListener: public IGameListener {
public:
    MOCK_METHOD(void, Update, (), (override));
    MOCK_METHOD(void, ShowGameState, (), (override));
};

TEST(ListenerTest, UpdateTest) {
    MockListener mockConsoleListener;

	IGamePtr game = IGame::Produce();

    EXPECT_CALL(mockConsoleListener, Update())
        .WillOnce([&game]() {
		std::array<Sign::sign, 9> board = game->GetGameBoard().GetBoard();

		for (auto index = 0; index < board.size(); ++index)
		{
			if (index % 3 == 0)
				std::cout << "\n";
			if (board[index] == Sign::sign::X)
				std::cout << "X ";
			else if (board[index] == Sign::sign::O)
				std::cout << "O ";
			else std::cout << "_ ";
		}
		std::cout << "\n";
            });

    mockConsoleListener.Update();
}

TEST(ListenerTest, ShowGameState) {
	MockListener mockConsoleListener;

	IGamePtr game = IGame::Produce();
	IPlayerPtr player = IPlayer::Produce();
	player->SetPlayerName("Test");
	player->SetSign(Sign::sign::X);
	game->PlaceSign(0, player);
	game->PlaceSign(4, player);
	game->PlaceSign(8, player);

	EXPECT_CALL(mockConsoleListener, ShowGameState())
		.WillOnce([&game]() {
		if (game->GetGameBoard().CheckGameState() == GameState::gameState::WonO)
		std::cout << "O won!\n";
		else if (game->GetGameBoard().CheckGameState() == GameState::gameState::WonX)
			std::cout << "X won!\n";
		else if (game->GetGameBoard().CheckGameState() == GameState::gameState::Tie) std::cout << "Tie!\n";
			});

	mockConsoleListener.ShowGameState();
}

TEST(BoardTest, IncorrectPlacement)
{
	MockListener mockConsoleListener;

	IGamePtr game = IGame::Produce();

	IPlayerPtr player = IPlayer::Produce();
	player->SetPlayerName("Test");

	player->SetSign(Sign::sign::X);
	EXPECT_EQ(game->PlaceSign(-1, player), false);
	EXPECT_EQ(game->PlaceSign(6, player), true);
	EXPECT_EQ(game->PlaceSign('a', player), false);
}

TEST(GameTest, PositionAlreadyOccupied)
{
	IGamePtr game = IGame::Produce();

	game->PlaceSign(0, game->GetPlayer());
	EXPECT_EQ(game->PlaceSign(0, game->GetPlayer()), false);
}

TEST(BoardTest, EmptyCells)
{
	IGamePtr game = IGame::Produce();

	game->PlaceSign(0, game->GetPlayer());
	EXPECT_EQ(game->GetGameBoard().GetEmptyCells().size(), 8);
}

TEST(BoardWin, CheckWinX)
{
	IGamePtr game = IGame::Produce();

	IPlayerPtr player1 = IPlayer::Produce();
	player1->SetSign(Sign::sign::X);
	IPlayerPtr player2 = IPlayer::Produce();
	player2->SetSign(Sign::sign::O);

	game->PlaceSign(0, player1);
	game->PlaceSign(2, player2);
	game->PlaceSign(3, player1);
	game->PlaceSign(5, player2);
	game->PlaceSign(6, player1);

	EXPECT_EQ(game->GetGameBoard().CheckGameState(), GameState::gameState::WonX);
}

TEST(BoardWin, CheckTie)
{
	IGamePtr game = IGame::Produce();

	IPlayerPtr player1 = IPlayer::Produce();
	player1->SetSign(Sign::sign::O);
	IPlayerPtr player2 = IPlayer::Produce();
	player2->SetSign(Sign::sign::X);

	game->PlaceSign(0, player1);
	game->PlaceSign(1, player2);
	game->PlaceSign(5, player1);
	game->PlaceSign(2, player2);
	game->PlaceSign(6, player1);
	game->PlaceSign(4, player2);	
	game->PlaceSign(7, player1);
	game->PlaceSign(8, player2);
	game->PlaceSign(3, player2);

	EXPECT_EQ(game->GetGameBoard().CheckGameState(), GameState::gameState::Tie);
}

TEST(BoardWin, CheckWinO)
{
	IGamePtr game = IGame::Produce();

	IPlayerPtr player1 = IPlayer::Produce();
	player1->SetSign(Sign::sign::O);
	IPlayerPtr player2 = IPlayer::Produce();
	player2->SetSign(Sign::sign::X);

	game->PlaceSign(0, player1);
	game->PlaceSign(3, player2);
	game->PlaceSign(1, player1);
	game->PlaceSign(4, player2);
	game->PlaceSign(2, player1);
	game->PlaceSign(8, player2);

	EXPECT_EQ(game->GetGameBoard().CheckGameState(), GameState::gameState::WonO);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}