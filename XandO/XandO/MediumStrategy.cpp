#include "MediumStrategy.h"


uint16_t MediumStrategy::GetNextMove(Board& board, const Sign::sign computerSign)
{
    if (initialized == false)
    {
        order.push(std::move(hardMove));
        order.push(std::move(easyMove));
        initialized = true;
    }
    
    if (order.front()->GetDifficulty() == Difficulty::Level::Hard)
    {
        auto nextMove = order.front()->GetNextMove(board, computerSign);
        order.push(std::move(order.front()));
        order.pop();
        return nextMove;
    }
    else {
        auto nextMove = order.front()->GetNextMove(board, computerSign);
        order.push(std::move(order.front()));
        order.pop();
        return nextMove;
    }
}

Difficulty::Level MediumStrategy::GetDifficulty() const
{
    return Difficulty::Level::Medium;
}
