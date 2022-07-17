#include "Chessboard.hpp"

int Chessboard::EvaluateMobility() 
{
    std::vector<Move> WhiteMoves = GetAllSidesMoves(white);
    std::vector<Move> BlackMoves = GetAllSidesMoves(black);

    int AmountOfWhiteMoves = WhiteMoves.size();

    int AmountOfBlackMoves = BlackMoves.size();

    if (SideToMove == white) 
    {
        return (AmountOfWhiteMoves - AmountOfBlackMoves);
    } else {
        return (AmountOfBlackMoves - AmountOfWhiteMoves);
    }
    return 0;
}


int const KingValue = 10000;
int const QueenValue = 900;
int const RookValue = 500;
int const BishopValue = 350;
int const KnightValue = 300;
int const PawnValue = 100;

int const ValueArray[6] = {PawnValue, BishopValue, KingValue, QueenValue, KnightValue, RookValue};


int Chessboard::EvaluateMaterial() {
    
    // TO be implemented

    int MaterialEval;

    int MaterialEvalWhite = 0;

    int MaterialEvalBlack = 0;
        
    for (int BitboardArrayIterator = 0; BitboardArrayIterator < 6; BitboardArrayIterator++)
    {
        MaterialEvalWhite += PopulationCount(*WhiteBitboardArry[BitboardArrayIterator]) * ValueArray[BitboardArrayIterator];    

        //std::cout << "White: " << MaterialEvalWhite << "\n";
    
        MaterialEvalBlack += PopulationCount(*BlackBitboardArry[BitboardArrayIterator]) * ValueArray[BitboardArrayIterator];    
    
        //std::cout << "Black: " << MaterialEvalBlack << "\n";
    }


    if (SideToMove == white) 
    {
        MaterialEval = MaterialEvalWhite - MaterialEvalBlack;
    } else {
        MaterialEval = MaterialEvalBlack - MaterialEvalWhite;
    }

    return MaterialEval;
}


// high good for white
int Chessboard::Evaluate() {    

    // To be implemented

    int Eval;

    int ConstantMultiplier;

    if (SideToMove == white) {
        ConstantMultiplier = 1;
    } else {
        ConstantMultiplier = -1;
    }

    // linear combination Eval
    // added up and multiplied by a constant
    Eval = (EvaluateMaterial() + EvaluateMobility()) * ConstantMultiplier;

    return Eval;

}

