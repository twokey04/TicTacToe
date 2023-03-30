#include "tests.h"

#include "Board.h"
#include "IGame.h"
#include "Game.h"
#include "GameState.h"
#include "IGameListener.h"
#include "IPlayer.h"
#include "Player.h"
#include "Sign.h"

class MockTest {
public:
    MOCK_METHOD(void, SomeMethod, ());
};

TEST(TestCaseName, TestName) {
    MockTest mock;
    EXPECT_CALL(mock, SomeMethod);
    mock.SomeMethod();
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
