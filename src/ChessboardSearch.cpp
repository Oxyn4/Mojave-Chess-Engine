#include "BoardConcepts.hpp"
#include "Chessboard.hpp"
#include "Bitboard.hpp"

#include <vector> 
#include <random>

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
