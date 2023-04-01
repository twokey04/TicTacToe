#include "HardStrategy.h"

uint16_t HardStrategy::GetNextMove(Board& board, const Sign::sign computerSign)
{
    int bestScore = std::numeric_limits<int>::min();
    uint16_t bestMove = 0;

    for (uint16_t i = 0; i < 9; i++) {
        if (board.GetBoard()[i] == Sign::sign::None) {
            board[i] = computerSign;
            int score = Minimax(board, 8, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false, computerSign);
            board[i] = Sign::sign::None;
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

int HardStrategy::Minimax(Board& board, int depth, int alpha, int beta, bool maximizingPlayer, const Sign::sign& computerSign)
{
    if (board.CheckWin(computerSign)) {
        return 10;
    }
    else if (board.CheckWin(computerSign == Sign::sign::X ? Sign::sign::O : Sign::sign::X)) {
        return -10;
    }
    else if (board.CheckTie()) {
        return 0;
    }

    if (depth == 0) {
        return 0;
    }

    int bestScore;
    if (maximizingPlayer) {
        bestScore = std::numeric_limits<int>::min();
        for (uint16_t i = 0; i < 9; i++) {
            if (board.GetBoard()[i] == Sign::sign::None) {
                board[i] = computerSign;
                int score = Minimax(board, depth - 1, alpha, beta, false, computerSign);
                board[i] = Sign::sign::None;
                bestScore = std::max(bestScore, score);
                alpha = std::max(alpha, score);
                if (beta <= alpha) {
                    break;
                }
            }
        }
    }
    else {
        bestScore = std::numeric_limits<int>::max();
        for (uint16_t i = 0; i < 9; i++) {
            if (board.GetBoard()[i] == Sign::sign::None) {
                board[i] = (computerSign == Sign::sign::X ? Sign::sign::O : Sign::sign::X);
                int score = Minimax(board, depth - 1, alpha, beta, true, computerSign);
                board[i] = Sign::sign::None;
                bestScore = std::min(bestScore, score);
                beta = std::min(beta, score);
                if (beta <= alpha) {
                    break;
                }
            }
        }
    }
    return bestScore;
}

Difficulty::Level HardStrategy::GetDifficulty() const
{
    return Difficulty::Level::Hard;
}
