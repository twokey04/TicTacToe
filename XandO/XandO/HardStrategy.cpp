#include "HardStrategy.h"

uint16_t HardStrategy::GetNextMove(Board& board, const Sign::sign computerSign)
{
    int bestScore = INT_MIN;
    uint16_t bestMove = 0;

    for (uint16_t i = 0; i < 9; i++) {
        if (board.GetBoard()[i] == Sign::sign::None) {
            board[i] = computerSign;
            int score = Minimax(board, computerSign, computerSign);
            board[i] = Sign::sign::None;
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    std::cout << bestMove;
    return bestMove;
}

int HardStrategy::Minimax(Board& board, const Sign::sign& playerSign, const Sign::sign& computerSign)
{
    if (board.CheckWin(playerSign)) {
        return -1;
    }
    else if (board.CheckWin(computerSign)) {
        return 1;
    }
    else if (board.CheckTie()) {
        return 0;
    }

    int bestScore;
    if (playerSign == computerSign) {
        bestScore = INT_MIN;
        for (uint16_t i = 0; i < 9; i++) {
            if (board.GetBoard()[i] == Sign::sign::None) {
                board[i] = computerSign;
                int score = Minimax(board, playerSign, computerSign);
                board[i] = Sign::sign::None;
                bestScore = std::max(bestScore, score);
            }
        }
    }
    else {
        bestScore = INT_MAX;
        for (uint16_t i = 0; i < 9; i++) {
            if (board.GetBoard()[i] == Sign::sign::None) {
                board[i] = playerSign;
                int score = Minimax(board, playerSign, computerSign);
                board[i] = Sign::sign::None;
                bestScore = std::min(bestScore, score);
            }
        }
    }
    return bestScore;
}