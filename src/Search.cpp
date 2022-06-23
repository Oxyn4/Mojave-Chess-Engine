#include "BoardConcepts.h"
#include "Chessboard.h"
#include "Bitboard.h"

#include <vector> 
#include <random>

Move* BestMove;

int Chessboard::SearchNegaMax(int Depth) 
{
    if (Depth == 0) 
    {
        return Evaluate();
    }

    std::vector<Move> AllMoves = GetAllSidesMoves(SideToMove);

    int MaxEval = -100000;

    for (int AllMovesiterator = 0; AllMovesiterator < AllMoves.size(); AllMovesiterator++)
    {
        DoMove(AllMoves[AllMovesiterator]);

        int Eval = -SearchNegaMax(Depth-1);

        UndoLastMove(AllMoves[AllMovesiterator]);

        if (Eval > MaxEval) 
        {
            MaxEval = Eval;
        }
    }
    
    return MaxEval;  
}

/*

    choose and make a random move for the currents sides turn 

*/
Move Chessboard::SearchRandom() 
{
    int RandomChoice;

    std::vector<Move> AllMoves = GetAllSidesMoves(SideToMove);

    srand(time(0));

    RandomChoice = rand() % AllMoves.size();

    return AllMoves[RandomChoice];
}
