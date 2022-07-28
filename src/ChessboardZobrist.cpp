#include "Chessboard.hpp"

void Chessboard::ZobristInit() 
{
    static int ZobristInitialised = false;

    if (ZobristInitialised==true) {return;}

   srand(time(0)); 

   ZobristBlackToMove = rand();

    for (int ZobristCastleRightsIterator = 0; ZobristCastleRightsIterator < 4; ZobristCastleRightsIterator++) 
    {
        ZobristCastlingRights[ZobristCastleRightsIterator] = rand();
    }

    for (int ZobristEnPassantIterator=0; ZobristEnPassantIterator < 8; ZobristEnPassantIterator++)
    {
        ZobristEnPassant[ZobristEnPassantIterator] = rand();
    }

    for (int ZobristSquareValuesIterator=0; ZobristSquareValuesIterator < 64; ZobristSquareValuesIterator++)
    {
        for (int ZobristPiecesValuesIterator=0; ZobristPiecesValuesIterator < 12; ZobristPiecesValuesIterator++)
        {
            ZobristPieceSquareValues[ZobristSquareValuesIterator][ZobristPiecesValuesIterator] = rand();
        }
    }
    
    ZobristInitialised = true;
}

int Chessboard::ZobristHash() 
{
    int Hash=0;

    if (SideToMove==black) 
    {
        Hash = Hash ^ ZobristBlackToMove;
    }

    for (int SquareIterator=0; SquareIterator < 64; SquareIterator++) 
    {
        int PieceType = GetPieceType(SquareIterator);

        Hash = Hash ^ ZobristPieceSquareValues[SquareIterator][PieceType];

    }

    return Hash;
}
