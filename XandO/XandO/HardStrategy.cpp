#include "HardStrategy.h"

uint16_t HardStrategy::GetNextMove(const Board& board, const Sign::sign computerSign)
{

    int bestScore = INT_MIN;
    std::vector<uint16_t> availablePositions = board.GetEmptyCells();

    for (uint16_t cell : availablePositions) {
        Board newBoard = board;
        newBoard.SetSign(cell, computerSign);

        int score;
        int index = Minimax(newBoard, (computerSign == Sign::sign::X) ? Sign::sign::O : Sign::sign::X, score);
        //TODO: implement minimax
        if ((computerSign == m_game->GetComputer()->GetSign() && score > bestScore) ||
            (computerSign == m_game->GetPlayer()->GetSign() && score < bestScore)) {
            bestScore = score;
            index = cell;
        }
    }

    return bestScore;

    //return INT16_MAX;
}
