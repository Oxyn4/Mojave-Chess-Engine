#include "Eval.h"
#include "Chessboard.h"

int const KingValue = 10000;
int const QueenValue = 900;
int const RookValue = 500;
int const BishopValue = 350;
int const KnightValue = 300;
int const PawnValue = 100;

int const ValueArray[6] = {PawnValue, BishopValue, KingValue, QueenValue, KnightValue, RookValue};


int CountMaterial(Chessboard &Board, int side) {
    
    int TotalValue = 0;

    if (side == 0) 
    {
        for (int BitboardArray = 0; BitboardArray < 6; BitboardArray++)
        {
            TotalValue += (PopulationCount(Board.WhiteBitboardArry[BitboardArray]) * ValueArray[BitboardArray]);
        }
        
    } else {
        for (int BitboardArray = 0; BitboardArray < 6; BitboardArray++)
        {
            TotalValue += (PopulationCount(Board.BlackBitboardArry[BitboardArray]) * ValueArray[BitboardArray]);
        }
    }

    return (TotalValue - 10000);
        
}

int Evaluate(Chessboard &Board, int side) {
    return 0;
}

